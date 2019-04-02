#pragma once


#include "factorize.h"

#include <algorithm>
#include <functional>


class Divisors
{
public:

	std::vector<std::vector<unsigned long long> > get_all_factorizations(unsigned long long No_of_divisors)
	{
		calc_all_factorizations(No_of_divisors);

		return all_factorizations_vec;
	}



private:

	Factorize fac;
	std::vector<std::vector<unsigned long long> > all_factorizations_vec{};


	void calc_all_factorizations(unsigned long long No_of_divisors)
	{
		all_factorizations_vec.clear();

		std::vector<unsigned long long> prime_factors = fac.factorize(No_of_divisors);
		all_factorizations_vec = get_all_factorizations(prime_factors);


		sort_multiple_vec_ascending_first_element(all_factorizations_vec);
	}


	std::vector<std::vector<unsigned long long> > get_all_factorizations(std::vector<unsigned long long>& prime_factors)
	{
		std::vector<std::vector<unsigned long long> > all_factors;

		sort_single_vec_descending(prime_factors);
		all_factors.push_back(prime_factors);

		std::vector<unsigned long long>::size_type index = 0, index2 = 1;
		add_all_poss_fac(all_factors, all_factors.at(0), index, index2);

		return all_factors;
	}


	void add_all_poss_fac(std::vector<std::vector<unsigned long long> >& factors, const std::vector<unsigned long long> last_factors, std::vector<unsigned long long>::size_type& current_first_index, std::vector<unsigned long long>::size_type& current_second_index)
	{
		if (last_factors.size() <= 1) return;

		while (index_valid(last_factors, current_first_index, current_second_index))
		{
			std::vector<unsigned long long> new_factors = get_factors_for_indizes(last_factors, current_first_index, current_second_index);
			if (!is_element_of(factors, new_factors))
			{
				factors.push_back(new_factors);
				std::vector<unsigned long long>::size_type index = 0, index2 = 1;
				add_all_poss_fac(factors, factors.at(factors.size()-1), index, index2);
			}

			increase_indizes(last_factors, current_first_index, current_second_index);
		}
	}


	bool is_element_of(const std::vector<std::vector<unsigned long long> >& factors, const std::vector<unsigned long long>& to_be_tested)
	{
		for (auto facs : factors)
		{
			if (facs == to_be_tested) return true;
		}

		return false;
	}


	std::vector<unsigned long long> get_factors_for_indizes(const std::vector<unsigned long long>& last_factors, const std::vector<unsigned long long>::size_type& current_first_index, const std::vector<unsigned long long>::size_type& current_second_index)
	{

		unsigned long long new_val = last_factors.at(current_first_index) * last_factors.at(current_second_index);

		std::vector<unsigned long long> new_factors{ new_val };

		for (std::vector<unsigned long long>::size_type i = 0; i < last_factors.size(); ++i)
		{
			if ( (i != current_first_index) && (i != current_second_index))
			{
				new_factors.push_back(last_factors.at(i));
			}
		}

		sort_single_vec_descending(new_factors);

		return new_factors;
	}


	bool index_valid(const std::vector<unsigned long long>& factors, const std::vector<unsigned long long>::size_type& current_first_index, const std::vector<unsigned long long>::size_type& current_second_index)
	{

		unsigned long long size = factors.size();
		if ((current_first_index > (size - 2)) && (current_second_index > (size - 1))) return false;

		return true;
	}


	void increase_indizes(const std::vector<unsigned long long>& factors, std::vector<unsigned long long>::size_type& current_first_index, std::vector<unsigned long long>::size_type& current_second_index)
	{
		unsigned long long size = factors.size();

		if (current_second_index < (size - 1))
		{
			current_second_index++;
		}
		else
		{
			current_first_index++;
			current_second_index=current_first_index+1;
		}
	}



	void sort_single_vec_descending(std::vector<unsigned long long>& to_be_sorted)
	{
		std::sort(to_be_sorted.begin(), to_be_sorted.end(), std::greater<unsigned long long>());
	}

	void sort_multiple_vec_ascending_first_element(std::vector<std::vector<unsigned long long> >& to_be_sorted)
	{
		std::sort(to_be_sorted.begin(), to_be_sorted.end(), [](const std::vector<unsigned long long>& lhs, const std::vector<unsigned long long>& rhs)
		{
			return lhs.at(0) < rhs.at(0);
		});
	}





};

