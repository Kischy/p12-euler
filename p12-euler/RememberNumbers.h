#pragma once

#include "IRememberNumbers.h"

#include <unordered_map>
#include <functional>


template <typename T_key, typename T_value>
class RememberNumbers : public IRememberNumbers<typename T_key, typename T_value>
{
public:
	RememberNumbers(std::function<T_value(T_key)> test_key_function)
	{
		test_number_key_function = test_key_function;
	}

	virtual T_value calc_and_get_number(T_key num_key) override
	{
		if (number_has_been_saved(num_key)) return get_number(num_key);


		T_value num_val = test_number_key_function(num_key);
		save_number(num_key, num_val);

		return num_val;
	}


private:
	//These functions have to be public for testing
	void save_number(T_key num_key, T_value num_value)
	{
		saved_numbers.insert({ num_key,num_value });
	}

	T_value get_number(T_key num_key) const
	{
		auto it = saved_numbers.find(num_key);
		return it->second;
	}

	bool number_has_been_saved(T_key num_key) const
	{
		auto it = saved_numbers.find(num_key);

		return it == saved_numbers.end() ? false : true;
	}
	//These functions have to be public for testing END


//private:
	std::function<T_value(T_key)> test_number_key_function;
	std::unordered_map<T_key, T_value> saved_numbers;



};

