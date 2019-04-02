#include <iostream>


#include "triangularfactorscounter.h"





int main(int argc, char **argv)
{


	std::cout << "Calculation started" << std::endl;

	Divisors divisors;

	unsigned long long p12_answ = 0;
	TriangularFactorsCounter tri_fac_count; 

	p12_answ = tri_fac_count.get_first_triangular_with_more_divisors(500);

	std::cout << "The answer to the 12th problem of ProjectEuler.Net is " << p12_answ << ".\n";


	return 0;
}
