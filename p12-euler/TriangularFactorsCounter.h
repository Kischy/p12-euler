#pragma once


#include "FactorsCounter.h"
#include "TriangularNumbers.h"



class TriangularFactorsCounter
{
public:
	InfInt get_first_triangular_with_divisors(const unsigned long long number_of_divisors)
	{
		if (!is_valid_input(number_of_divisors)) return 0;

		unsigned long long No_of_divisors = 0, triangular_pos = 0;

		InfInt current_triangular = 0;

		while (No_of_divisors != number_of_divisors)
		{
			current_triangular = get_triangular(triangular_pos);

			No_of_divisors = FactorsCounter::get_number_of_divisors(current_triangular);

			triangular_pos++;
		}



		return current_triangular;
	}


private:

	TriangularNumbers tri;

	bool is_valid_input(const unsigned long long number) const
	{
		if (number == 0) return false;

		return true;
	}

	InfInt get_triangular(const unsigned long long pos)
	{
		return tri.get_triangular(pos);
	}


};


