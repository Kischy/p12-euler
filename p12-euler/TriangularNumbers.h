#pragma once

#include <vector>

#include "InfInt.h"


class TriangularNumbers
{
public:

	InfInt get_triangular( const unsigned long long pos);

private:   

	std::vector<InfInt> triangular_numbers{0,1};


	InfInt calc_triangular_number(const unsigned long long pos) ;

	bool triangular_has_been_saved(const unsigned long long pos) const;

	void save_triangular_number(const InfInt triangular);

	InfInt get_saved_triangular(const unsigned long long pos) const;

};

