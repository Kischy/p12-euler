#pragma once


class FactorsCounter
{
public:

	static unsigned long long get_number_of_divisors(const unsigned long long number) 
	{
		if (is_simple_number(number)) return number;

		unsigned long long divisor_count = 2; //Set to two because the number is divisable by 1 and itself


		for (unsigned long long i = 2; i <= (number/2); ++i)
		{
			if (is_divisible(number, i)) divisor_count++;
		}


		return divisor_count;
	}


private:

	static bool is_simple_number(const unsigned long long number) 
	{
		if (number <= 1) return true;

		return false;
	}


	static bool is_divisible(const unsigned long long number, const unsigned long long divisor) 
	{
		return (number % divisor) == 0;
	}



};