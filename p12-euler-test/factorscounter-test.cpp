#include "pch.h"

#include "../p12-euler/factorscounter.h"

class FactorsCounterTest : public testing::Test
{
public:
	FactorsCounter fac_count;
};



TEST_F(FactorsCounterTest, GivesBackZeroOnZeroCall)
{
	ASSERT_EQ(fac_count.get_number_of_divisors(0), 0);
}

TEST_F(FactorsCounterTest, GivesBackOneOnOneCall)
{
	ASSERT_EQ(fac_count.get_number_of_divisors(1), 1);
}

TEST_F(FactorsCounterTest, GivesBackNumberOfDivisorsEven)
{
	unsigned long long number_of_divisors = 6;
	ASSERT_EQ(fac_count.get_number_of_divisors(28), number_of_divisors);
}

TEST_F(FactorsCounterTest, GivesBackNumberOfDivisorsOdd)
{
	unsigned long long number_of_divisors = 4;
	ASSERT_EQ(fac_count.get_number_of_divisors(21), number_of_divisors);
}
