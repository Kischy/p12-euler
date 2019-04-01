#pragma once


#include "FactorsCounter.h"
#include "TriangularNumbers.h"




class TriangularFactorsCounter
{
public:
	unsigned long long get_first_triangular_with_more_divisors(const unsigned long long number_of_divisors, const unsigned long long lowest_with_n_divisors = 1)
	{
		if (!is_valid_input(number_of_divisors)) return 0;

		unsigned long long No_of_divisors = 0, triangular_pos = 0;
		unsigned long long current_triangular = 0;

		unsigned long long lowest_number_with_number_of_divisors = 0;

		if (lowest_with_n_divisors == 1)
		{
			lowest_number_with_number_of_divisors = find_lowest_number(number_of_divisors);
		}
		else
		{
			lowest_number_with_number_of_divisors = lowest_with_n_divisors;
		}
		
			   
		triangular_pos = find_higher_triangular_pos(lowest_number_with_number_of_divisors);
		current_triangular = get_triangular(triangular_pos);

		while (No_of_divisors <= number_of_divisors)
		{
			current_triangular = get_triangular(triangular_pos);

			No_of_divisors = factors_counter.get_number_of_divisors(current_triangular);

			triangular_pos++;
		}



		return current_triangular;
	}


private:

	TriangularNumbers tri;
	FactorsCounter factors_counter;

	bool is_valid_input(const unsigned long long number) const
	{
		if (number == 0) return false;

		return true;
	}

	unsigned long long get_triangular(const unsigned long long pos)
	{
		return tri.get_triangular(pos);
	}

	unsigned long long find_lowest_number(const unsigned long long number_of_divisors)
	{
		unsigned long long No_of_divisors = 0;
		unsigned long long current_number = 0;

		while (No_of_divisors != number_of_divisors)
		{
			current_number++;
			No_of_divisors = factors_counter.get_number_of_divisors(current_number);
		}

		return current_number;
	}

	unsigned long long find_higher_triangular_pos(unsigned long long number)
	{
		unsigned long long current_triangular = 0;
		unsigned long long pos = 0;

		while (current_triangular < number)
		{
			pos++;
			current_triangular = get_triangular(pos);
		}

		return pos;
	}

};


