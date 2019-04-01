#include "pch.h"

#include "../p12-euler/Divisors.h"

#include "../p12-euler/Factorize.h"

class DivisorsFactorizationTesting : public testing::Test
{
public:
	Divisors divisors;

	Factorize fac;

};


TEST_F(DivisorsFactorizationTesting, FindAllPossibleFactorizationsOf16)
{
	std::vector<std::vector<unsigned long long >> allFacsof_16 = { { 2,2,2,2 }, {4,2,2},{4,4},{8,2},{16} };

	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(16);

	for (unsigned int i = 0; i <= 4; ++i)
	{
		ASSERT_EQ(allFacsof_16.at(i), result.at(i));
	}

}


TEST_F(DivisorsFactorizationTesting, FindAllPossibleFactorizationsOf465)
{
	std::vector<std::vector<unsigned long long >> allFacsof_465 = { { 31,5,3 }, {31,15},{93,5},{155,3},{465} };

	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(465);

	for (unsigned int i = 0; i <= 4; ++i)
	{
		ASSERT_EQ(allFacsof_465.at(i), result.at(i));
	}

}
