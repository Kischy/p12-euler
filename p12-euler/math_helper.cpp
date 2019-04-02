#include "math_helper.h"


namespace helper
{
	unsigned long long LLPow(unsigned long long base, unsigned long long exponent)
	{
		if (base == 0) return 0;
		else if (exponent == 0) return 1;
		else if (exponent == 1) return base;

		return base * LLPow(base, exponent - 1);
	}

}

