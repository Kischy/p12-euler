#pragma once

#include "RememberNumbers.h"

#include <climits>


class TriangularNumbers
{
public:

	unsigned long long get_triangular( const unsigned long long pos);

private:
	   
	RememberNumbers<unsigned long long, unsigned long long> triangular_numbers{ std::bind(&TriangularNumbers::calc_triangular_number, this,std::placeholders::_1) };

	unsigned long long get_triangular_number(const unsigned long long pos);

	unsigned long long calc_triangular_number(const unsigned long long pos) const;



};

