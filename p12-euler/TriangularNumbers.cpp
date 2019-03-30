#include "TriangularNumbers.h"


namespace //anonymous namespace
{
	bool is_valid_position(unsigned long long pos)
	{
		if (pos == 0) return false;

		return true;
	}




}  //anonymous namespace END



unsigned long long TriangularNumbers::get_triangular(unsigned long long pos)  
{
	return get_triangular_number(pos);
}

unsigned long long TriangularNumbers::get_triangular_number(unsigned long long pos)
{	

	return triangular_numbers.calc_and_get_number(pos);
}

unsigned long long TriangularNumbers::calc_triangular_number(unsigned long long pos) const
{
	if (!is_valid_position(pos)) return 0;

	unsigned long long sum = 0;

	for (unsigned long long i = 1; i <= pos; ++i)
	{
		sum += i;
	}


	return sum;
}



