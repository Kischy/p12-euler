#pragma once


class FactorsCounter
{
public:

	unsigned long long get_number_of_divisors(const unsigned long long number) const
	{
		if (!is_valid_input(number)) return 0;

		unsigned long long divisor_count = 2; //Set to two because the number is divisable by 1 and itself


		for (unsigned long long i = 2; i <= (number/2); ++i)
		{
			if (is_divisible(number, i)) divisor_count++;
		}


		return divisor_count;
	}


private:

	bool is_valid_input(const unsigned long long number) const
	{
		if (number == 0) return false;

		return true;
	}


	bool is_divisible(const unsigned long long number, const unsigned long long divisor) const
	{
		return (number % divisor) == 0;
	}



};