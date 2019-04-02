#pragma once

#include <vector>
#include "primechecker.h"
#include "primenumbers.h"




class Factorize
{
public:

	std::vector<unsigned long long> factorize(const unsigned long long number) 
	{
		factorize_pr(number);

		return intern_factors;
	}


	std::vector<unsigned long long> factorize_exponent(const unsigned long long number)
	{
		factorize_with_exponents(number);

		return intern_factors_with_exponents;
	}




private:
	PrimeChecker primechecker;
	PrimeNumbers primenumbers;
	std::vector<unsigned long long> intern_factors{};
	std::vector<unsigned long long> intern_factors_with_exponents{};


	void factorize_pr(const unsigned long long number)
	{
		intern_factors.clear();

		if (is_number_to_low(number))
		{
			intern_factors.push_back(number);
			return;
		}

		factor_to_intern_vector(number);
	}


	void factorize_with_exponents(const unsigned long long number)
	{
		factorize_pr(number);
		if (intern_factors.empty()) return;

		intern_factors_with_exponents.clear();

		unsigned long long fac = intern_factors.at(0), exponent = 0;

		for (unsigned long long factor : intern_factors)
		{
			if (fac == factor)
			{
				exponent++;
			}
			else
			{
				add_factor_and_exponent(fac, exponent);
				fac = factor;
				exponent = 1;
			}
		}

		// Add the last number
		add_factor_and_exponent(fac, exponent);
	}

	

	void add_factor_and_exponent(const unsigned long long factor, const unsigned long long exponent)
	{
		intern_factors_with_exponents.push_back(factor);
		intern_factors_with_exponents.push_back(exponent);
	}

	
	bool is_number_to_low(const unsigned long long number)
	{
		if (number <= 3)
			return true;

		return false;
	}


	void factor_to_intern_vector(unsigned long long number)
	{

		while (!primechecker.is_prime_number(number))
		{
			unsigned long long lowest = find_lowest_prime_factor(number);
			intern_factors.push_back(lowest);
			number /= lowest;
		}
				
		//This is the last prime factor
		intern_factors.push_back(number);
	}



	unsigned long long find_lowest_prime_factor(const unsigned long long number)
	{
		unsigned long long current_prime = 2;

		for (unsigned long long prime_i = 1; current_prime <= number; ++prime_i)
		{
			current_prime = primenumbers.get_prime(prime_i);
			if (is_divisable(number, current_prime))
			{
				return current_prime;
			}
		}

		return number;
	}


	bool is_divisable(const unsigned long long number, const unsigned long long divisor)
	{
		return (number % divisor) == 0;
	}



};

