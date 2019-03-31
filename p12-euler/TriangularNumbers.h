#pragma once

#include <vector>


class TriangularNumbers
{
public:

	unsigned long long get_triangular( const unsigned long long pos);

private:   

	std::vector<unsigned long long> triangular_numbers{0,1};


	unsigned long long calc_triangular_number(const unsigned long long pos) ;

	bool triangular_has_been_saved(const unsigned long long pos) const;

	void save_triangular_number(const unsigned long long triangular);

	unsigned long long get_saved_triangular(const unsigned long long pos) const;

};

