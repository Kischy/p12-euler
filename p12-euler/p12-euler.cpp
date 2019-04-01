#include <iostream>


#include "TriangularFactorsCounter.h"

#include "Divisors.h"





int main(int argc, char **argv)
{

	std::cout << "Calculation started" << std::endl;

	Divisors divisors;

	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(16);


	unsigned long long p12_answ = 0;
	TriangularFactorsCounter tri_fac_count; 


	//62370000 is the smallest number with 500 divisors
	p12_answ = tri_fac_count.get_first_triangular_with_more_divisors(500, 62370000);

	std::cout << "The answer to the 12th problem of ProjectEuler.Net is " << p12_answ << ".\n";


	return 0;
}
