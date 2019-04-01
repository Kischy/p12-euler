#include "pch.h"

#include "../p12-euler/TriangularFactorsCounter.h"


class TriangularFactorsCounterTest : public testing::Test
{
public:
	TriangularFactorsCounter fac_count;
};



TEST_F(TriangularFactorsCounterTest, GivesBackZeroOnZeroCall)
{
	ASSERT_EQ(fac_count.get_first_triangular_with_more_divisors(0), 0);
}

TEST_F(TriangularFactorsCounterTest, GivesBackTriangularNumberWithNumberOfDivisors_HighNumber_num_2)
{
	ASSERT_EQ(fac_count.get_first_triangular_with_more_divisors(2), 6);
	//ASSERT_EQ(fac_count.get_first_triangular_with_divisors(200), 7248528);
}


TEST_F(TriangularFactorsCounterTest, GivesBackTriangularNumberWithNumberOfDivisors_HighNumber_num_3)
{
	ASSERT_EQ(fac_count.get_first_triangular_with_more_divisors(3), 6);
	//ASSERT_EQ(fac_count.get_first_triangular_with_divisors(200), 7248528);
}


TEST_F(TriangularFactorsCounterTest, GivesBackTriangularNumberWithNumberOfDivisors_num_4)
{
	unsigned long long first_triangular_with_four_divisors = 28;
	ASSERT_EQ(fac_count.get_first_triangular_with_more_divisors(4), first_triangular_with_four_divisors);
}


TEST_F(TriangularFactorsCounterTest, GivesBackTriangularNumberWithNumberOfDivisors_HighNumber_num_5)
{
	ASSERT_EQ(fac_count.get_first_triangular_with_more_divisors(5), 28);
	//ASSERT_EQ(fac_count.get_first_triangular_with_divisors(200), 7248528);
}


