#include "pch.h"

#include "../p12-euler/factorize.h"


class FactorizeChecker : public testing::Test
{
public:
	Factorize factorize;
};

class FactorizeExponentialChecker : public testing::Test
{
public:
	Factorize factorize;
};


TEST(FactorizeTester, FactorizeClassExists) {
	Factorize factorize;

	//ASSERT_FALSE(primechecker.is_prime_number(0));
	//ASSERT_FALSE(primechecker.is_prime_number(1));
}

TEST_F(FactorizeChecker, FactorizationOf_number_2)
{
	std::vector<unsigned long long> factors = { 2 };
	ASSERT_EQ(factorize.factorize(2), factors);
}

TEST_F(FactorizeChecker, FactorizationOf_number_6)
{
	std::vector<unsigned long long> factors = { 2, 3 };
	ASSERT_EQ(factorize.factorize(6), factors);
}


TEST_F(FactorizeChecker, FactorizationOf_number_32134)
{
	std::vector<unsigned long long> factors = { 2,16067 };
	ASSERT_EQ(factorize.factorize(32134), factors);
}


TEST_F(FactorizeChecker, FactorizationOf_number_23132)
{
	std::vector<unsigned long long> factors = { 2,2,5783 };
	ASSERT_EQ(factorize.factorize(23132), factors);
}

TEST_F(FactorizeChecker, FactorizationOf36)
{
	std::vector<unsigned long long> factors = { 2,2,3,3 };
	ASSERT_EQ(factorize.factorize(36), factors);
}

TEST_F(FactorizeChecker, FactorizationOf720720)
{
	std::vector<unsigned long long> factors = { 2,2,2,2,3,3,5,7,11,13 };
	ASSERT_EQ(factorize.factorize(720720), factors);
}



TEST_F(FactorizeChecker, HandelingOfLowNumbers)
{
	std::vector<unsigned long long> factors = { 2 };
	ASSERT_EQ(factorize.factorize(2), factors);
	std::vector<unsigned long long> factors2 = { 1 };
	ASSERT_EQ(factorize.factorize(1), factors2);
	std::vector<unsigned long long> factor3 = { 0 };
	ASSERT_EQ(factorize.factorize(0), factor3);
}



TEST_F(FactorizeChecker, PerformenceChecker) //Takes about 360 ms at the moment
{
	for (unsigned long long i = 0; i < 10000; ++i)
	{
		factorize.factorize(i);
	}
}




TEST_F(FactorizeExponentialChecker, FactorizeWithExponent_number_36)
{
	std::vector<unsigned long long> factors_with_exponents_number_36 = { 2,2,3,2 };
	ASSERT_EQ(factorize.factorize_exponent(36), factors_with_exponents_number_36);

}

TEST_F(FactorizeExponentialChecker, FactorizeWithExponent_number_144)
{
	std::vector<unsigned long long> factors_with_exponents_number_144 = { 2,4,3,2 };
	ASSERT_EQ(factorize.factorize_exponent(144), factors_with_exponents_number_144);
}

TEST_F(FactorizeExponentialChecker, HandelingOfLowNumbers)
{
	std::vector<unsigned long long> factors = { 2,1 };
	ASSERT_EQ(factorize.factorize_exponent(2), factors);
	std::vector<unsigned long long> factors2 = { 1,1 };
	ASSERT_EQ(factorize.factorize_exponent(1), factors2);
	std::vector<unsigned long long> factor3 = { 0,1 };
	ASSERT_EQ(factorize.factorize_exponent(0), factor3);
}

TEST_F(FactorizeExponentialChecker, FactorizeWithExponent_number_23132)
{
	std::vector<unsigned long long> factors = { 2,2,5783,1 };
	ASSERT_EQ(factorize.factorize_exponent(23132), factors);
}

TEST_F(FactorizeExponentialChecker, FactorizeWithExponent_number_32134)
{
	std::vector<unsigned long long> factors = { 2,1,16067,1 };
	ASSERT_EQ(factorize.factorize_exponent(32134), factors);
}

TEST_F(FactorizeExponentialChecker, FactorizeWithExponent_number_9646541212452)
{
	std::vector<unsigned long long> factors = { 2,2,3,1,23,1,139,1,8941,1,28123,1 };
	ASSERT_EQ(factorize.factorize_exponent(9646541212452), factors);
}


TEST_F(FactorizeExponentialChecker, PerformenceChecker) //Takes about 360 ms at the moment
{
	for (unsigned long long i = 0; i < 10000; ++i)
	{
		factorize.factorize_exponent(i);
	}
}



