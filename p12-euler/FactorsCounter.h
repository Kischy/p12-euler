#pragma once

#include "InfInt.h"


class FactorsCounter
{
public:

	static unsigned long long get_number_of_divisors(const InfInt& number)
	{
		if (is_simple_number(number)) return number.toUnsignedLongLong();

		unsigned long long divisor_count = 2; //Set to two because the number is divisable by 1 and itself

		InfInt i = 2;

		for (i = 2; i <= (number/2); ++i)
		{
			if (is_divisible(number, i)) divisor_count++;
		}


		return divisor_count;
	}


private:

	inline static bool is_simple_number(const InfInt& number)
	{
		if (number <= 1) return true;

		return false;
	}


	inline static bool is_divisible(const InfInt& number, const InfInt& divisor)
	{
		return (number % divisor) == 0;
	}



};