#pragma once

#include "PrimeChecker.h"

#include <climits>


class PrimeNumbers
{
public:

	unsigned long long get_prime(unsigned long long position)
	{
		return remember_primes_and_positions.calc_and_get_number(position);
	}


private:
	RememberNumbers<unsigned long long, unsigned long long> remember_primes_and_positions{ std::bind(&PrimeNumbers::get_prime_at_position, this,std::placeholders::_1) };


	unsigned long long get_prime_at_position(unsigned long long position) const
	{
		if (position == 0) return 0;

		unsigned long long prime_to_be_found_at_position = 2, current_position = 0;

		while (prime_to_be_found_at_position != ULLONG_MAX)
		{
			if (PrimeChecker::is_prime_number_static(prime_to_be_found_at_position) == true)
			{
				current_position++;

				if (current_position == position)
				{
					return prime_to_be_found_at_position;
				}
			}

			prime_to_be_found_at_position++;
		}
	
		return 0;
	}

	



};



