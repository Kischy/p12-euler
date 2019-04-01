#pragma once


#include <cmath>


 #include "RememberNumbers.h"




class PrimeChecker
{
public:
	bool is_prime_number(unsigned long long number)
	{
		return remember_primes.calc_and_get_number(number);
	}

	static bool is_prime_number_static(unsigned long long number)
	{
		return PrimeChecker::is_prime(number);
	}


	
private:
	RememberNumbers<unsigned long long, bool> remember_primes{ &PrimeChecker::is_prime };


	static bool is_prime(unsigned long long number)
	{
		if (number <= 3) return numbers_until_three(number);

		return is_a_prime_higher_three(number);
	}


	static bool numbers_until_three(unsigned long long number) 
	{
		if (number == 2 || number == 3) return true;

		return false;
	}


	static bool is_a_prime_higher_three(unsigned long long number) 
	{
		unsigned long long upper = get_upper_limit(number);

		for (unsigned long long i = 2; i <= upper; ++i)
		{
			if (is_divisable(number, i)) return false;
		}

		return true;
	}

	static unsigned long long get_upper_limit(unsigned long long number) 
	{
		return static_cast<unsigned long long>( std::sqrt(number) + 1);
	}



	static bool is_divisable(unsigned long long number, unsigned long long divisor)
	{
		return (number % divisor) == 0;
	}


};



