#include <iostream>


#include "TriangularFactorsCounter.h"


int main(int argc, char **argv)
{
	unsigned long long p12_answ = 0;


	TriangularFactorsCounter tri_counter;

	p12_answ = tri_counter.get_first_triangular_with_divisors(500);


	std::cout << "The answer to the 12th problem of ProjectEuler.Net is " << p12_answ << ".\n";


	return 0;
}