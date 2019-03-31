#include <iostream>


#include "TriangularFactorsCounter.h"


#include "InfInt.h"


int main(int argc, char **argv)
{
	InfInt p12_answ = 0, triangle = 0;


	TriangularNumbers numbers;

	triangle = numbers.get_triangular(10000);



	p12_answ = FactorsCounter::get_number_of_divisors(triangle);


	std::cout << "The answer to the 12th problem of ProjectEuler.Net is " << triangle << ".\n";


	return 0;
}