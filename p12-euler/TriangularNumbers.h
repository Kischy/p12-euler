#pragma once

#include <vector>



class TriangularNumbers
{
public:

	unsigned long long get_triangular( const unsigned long long pos);

private:   

	std::vector<unsigned long long> triangular_numbers{0,1};


	inline unsigned long long calc_triangular_number(const unsigned long long pos) ;

	inline bool triangular_has_been_saved(const unsigned long long pos) const;

	inline void save_triangular_number(const unsigned long long triangular);

	inline unsigned long long get_saved_triangular(const unsigned long long pos) const;

};

