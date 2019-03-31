#pragma once


class FactorsCounter
{
public:

	static unsigned long long get_number_of_divisors(const unsigned long long& number)
	{
		if (is_simple_number(number)) return get_simple_number(number);

		unsigned long long divisor_count = 2; //Set to two because the number is divisable by 1 and itself

		unsigned long long i = 2, upper = number/2;

		if (is_divisible(number, 2))
		{
			for (i = 2; i <= upper; ++i)
			{
				if (is_divisible(number, i)) divisor_count++;
			}
		}
		else
		{
			for (i = 3; i <= upper; i+=2)
			{
				if (is_divisible(number, i)) divisor_count++;
			}
		}


		return divisor_count;
	}


private:

	inline static bool is_simple_number(const unsigned long long& number)
	{
		if (number <= 1) return true;

		return false;
	}

	inline static unsigned long long get_simple_number(const unsigned long long& number)
	{
		if (number == 1) return 1;

		return 0;
	}


	inline static bool is_divisible(const unsigned long long& number, const unsigned long long& divisor)
	{
		return (number % divisor) == 0;
	}



};