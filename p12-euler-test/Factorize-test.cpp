#include "pch.h"

#include "../p12-euler/Factorize.h"


class FactorizeChecker : public testing::Test
{
public:
	Factorize factorize;
};


TEST(FactorizeTester, FactorizeClassExists) {
	Factorize factorize;

	//ASSERT_FALSE(primechecker.is_prime_number(0));
	//ASSERT_FALSE(primechecker.is_prime_number(1));
}

TEST_F(FactorizeChecker, FactorizationOfTwo)
{
	std::vector<unsigned long long> factors = { 2 };
	ASSERT_EQ(factorize.factorize(2), factors);
}

TEST_F(FactorizeChecker, FactorizationOfSix)
{
	std::vector<unsigned long long> factors = { 2, 3 };
	ASSERT_EQ(factorize.factorize(6), factors);
}


TEST_F(FactorizeChecker, FactorizationOf32134)
{
	std::vector<unsigned long long> factors = { 2,16067 };
	ASSERT_EQ(factorize.factorize(32134), factors);
}


TEST_F(FactorizeChecker, FactorizationOf23132)
{
	std::vector<unsigned long long> factors = { 2,2,5783 };
	ASSERT_EQ(factorize.factorize(23132), factors);
}

TEST_F(FactorizeChecker, FactorizationOf36)
{
	std::vector<unsigned long long> factors = { 2,2,3,3 };
	ASSERT_EQ(factorize.factorize(36), factors);
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

