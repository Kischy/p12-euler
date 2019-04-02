#include "pch.h"

#include "../p12-euler/divisors.h"

#include "../p12-euler/factorize.h"

class DivisorsFactorizationTesting : public testing::Test
{
public:
	Divisors divisors;



};

class FindNumbersOfDivisorsTesting : public testing::Test
{
public:
	Divisors divisors;


};



TEST_F(DivisorsFactorizationTesting, FindAllPossibleFactorizationsOf16)
{
	std::vector<std::vector<unsigned long long >> allFacsof_16 = { { 2,2,2,2 }, {4,2,2},{4,4},{8,2},{16} };

	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(16);

	for (unsigned int i = 0; i < allFacsof_16.size(); ++i)
	{
		ASSERT_EQ(allFacsof_16.at(i), result.at(i));
	}

}


TEST_F(DivisorsFactorizationTesting, FindAllPossibleFactorizationsOf465)
{
	std::vector<std::vector<unsigned long long >> allFacsof_465 = { { 31,5,3 }, {31,15},{93,5},{155,3},{465} };

	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(465);

	for (unsigned int i = 0; i < allFacsof_465.size(); ++i)
	{
		ASSERT_EQ(allFacsof_465.at(i), result.at(i));
	}

}

TEST_F(DivisorsFactorizationTesting, FindAllPossibleFactorizationsOf11)
{
	std::vector<std::vector<unsigned long long >> allFacsof_11 = { {11} };

	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(11);

	for (unsigned int i = 0; i < allFacsof_11.size(); ++i)
	{
		ASSERT_EQ(allFacsof_11.at(i), result.at(i));
	}

}

TEST_F(DivisorsFactorizationTesting, HandelingOfLowNumbers)
{
	std::vector<std::vector<unsigned long long >> allFacsof_0 = { {0} };
	std::vector<std::vector<unsigned long long >> result = divisors.get_all_factorizations(0);

	for (unsigned int i = 0; i < allFacsof_0.size(); ++i)
	{
		ASSERT_EQ(allFacsof_0.at(i), result.at(i));
	}

	std::vector<std::vector<unsigned long long >> allFacsof_1 = { {1} };
	result = divisors.get_all_factorizations(1);

	for (unsigned int i = 0; i < allFacsof_1.size(); ++i)
	{
		ASSERT_EQ(allFacsof_1.at(i), result.at(i));
	}

	std::vector<std::vector<unsigned long long >> allFacsof_2 = { {2} };
	result = divisors.get_all_factorizations(2);

	for (unsigned int i = 0; i < allFacsof_2.size(); ++i)
	{
		ASSERT_EQ(allFacsof_2.at(i), result.at(i));
	}

}


TEST_F(FindNumbersOfDivisorsTesting, LowestNumberWith_500_Divisors)
{
	unsigned long long lowest_500_divisors = 62370000;

	ASSERT_EQ(divisors.lowest_number(500), lowest_500_divisors);


}

TEST_F(FindNumbersOfDivisorsTesting, LowestNumberWith_3_Divisors)
{
	unsigned long long lowest_3_divisors = 8;
	ASSERT_EQ(divisors.lowest_number(3), lowest_3_divisors);
}


TEST_F(FindNumbersOfDivisorsTesting, GivesBackOneForNumbersLowerThan3)
{
	for (unsigned long long i = 0; i < 3; ++i)
	{
		ASSERT_EQ(divisors.lowest_number(i), 1);
	}
}


