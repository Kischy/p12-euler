#include "TriangularNumbers.h"

unsigned long long TriangularNumbers::get_triangular(unsigned long long pos) const 
{
	if (!is_valid_position(pos)) return 0;

	return pos;
}

bool TriangularNumbers::is_valid_position(unsigned long long pos) const
{
	if(pos == 0) return false;

	return false;
}
