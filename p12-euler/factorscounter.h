#pragma once


#include "factorize.h"

class FactorsCounter
{
public:

	unsigned long long get_number_of_divisors(const unsigned long long number)
	{
		if (is_simple_number(number)) return get_simple_number(number);

		std::vector<unsigned long long> fac_exp = factorizer.factorize_exponent(number);


		return get_num_divisors(number);
	}


private:
	Factorize factorizer;



	unsigned long long get_num_divisors(const unsigned long long number)
	{
		std::vector<unsigned long long> fac_exp = factorizer.factorize_exponent(number);

		unsigned long long no_of_divisors = 1;


		//Every second element is a exponent
		for (std::vector<unsigned long long>::size_type i = 1; i < fac_exp.size(); i += 2)
		{
			no_of_divisors *= (fac_exp.at(i) + 1);
		}

		return no_of_divisors;

	}


	bool is_simple_number(const unsigned long long number) const
	{
		if (number <= 1) return true;

		return false;
	}

	unsigned long long get_simple_number(const unsigned long long number) const
	{
		if (number == 1) return 1;

		return 0;
	}





};
