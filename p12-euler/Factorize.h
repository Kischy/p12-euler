#pragma once

#include <vector>
#include "PrimeChecker.h"




class Factorize
{
public:

	std::vector<unsigned long long> factorize(unsigned long long number) 
	{
		intern_factors.clear();
			
		if (is_number_to_low(number) == true)
		{
			intern_factors.push_back(number);
			return intern_factors;
		}

		factor_to_intern_vector(number);

		return intern_factors;
	}



private:
	PrimeChecker primechecker;
	std::vector<unsigned long long> intern_factors;
	
	bool is_number_to_low(unsigned long long number)
	{
		if (number <= 3)
			return true;

		return false;
	}


	void factor_to_intern_vector(unsigned long long number)
	{

		while (primechecker.is_prime_number(number) == false)
		{
			unsigned long long lowest = find_lowest_prime_factor(number);
			intern_factors.push_back(lowest);
			number /= lowest;
		}
				
		//This is the last prime factor
		intern_factors.push_back(number);
	}



	unsigned long long find_lowest_prime_factor(unsigned long long number)
	{
		for (unsigned long long i = 2; i <= number; ++i)
		{
			if (primechecker.is_prime_number(i) == true)
			{
				if (is_divisable(number, i) == true)
				{
					return i;
				}
			}
		}
	}


	bool is_divisable(unsigned long long number, unsigned long long divisor)
	{
		return (number % divisor) == 0;
	}



};

