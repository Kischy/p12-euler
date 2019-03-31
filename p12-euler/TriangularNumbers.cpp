#include "TriangularNumbers.h"


namespace //anonymous namespace
{
	bool is_valid_position(const unsigned long long pos)
	{
		if (pos == 0) return false;

		return true;
	}




}  //anonymous namespace END



InfInt TriangularNumbers::get_triangular(const unsigned long long pos)
{
	return calc_triangular_number(pos);
}



InfInt TriangularNumbers::calc_triangular_number(const unsigned long long pos)
{	
	if (triangular_has_been_saved(pos)) return get_saved_triangular(pos);
	
	InfInt position = pos;

	InfInt triangular_number = (position *(position+1))/2;

	save_triangular_number(triangular_number);


	return triangular_number;
}

bool TriangularNumbers::triangular_has_been_saved(const unsigned long long pos) const
{
	if (pos <= triangular_numbers.size()-1  ) return true;

	return false;
}

void TriangularNumbers::save_triangular_number(const InfInt triangular)
{
	triangular_numbers.push_back(triangular);
}

InfInt TriangularNumbers::get_saved_triangular(const unsigned long long pos) const
{
	return triangular_numbers.at(pos);
}



