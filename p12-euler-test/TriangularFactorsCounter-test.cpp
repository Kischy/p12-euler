#include "pch.h"

#include "../p12-euler/TriangularFactorsCounter.h"


class TriangularFactorsCounterTest : public testing::Test
{
public:
	TriangularFactorsCounter fac_count;
};



TEST_F(TriangularFactorsCounterTest, GivesBackZeroOnZeroCall)
{
	ASSERT_EQ(fac_count.get_first_triangular_with_divisors(0), 0);
}


TEST_F(TriangularFactorsCounterTest, GivesBackTriangularNumberWithNumberOfDivisors)
{
	unsigned long long first_triangular_with_four_divisors = 6;
	ASSERT_EQ(fac_count.get_first_triangular_with_divisors(4), first_triangular_with_four_divisors);
}


TEST_F(TriangularFactorsCounterTest, GivesBackTriangularNumberWithNumberOfDivisors_HighNumber)
{
	ASSERT_EQ(fac_count.get_first_triangular_with_divisors(10), 496);
	//ASSERT_EQ(fac_count.get_first_triangular_with_divisors(200), 7248528);
}


