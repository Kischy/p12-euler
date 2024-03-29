#include "pch.h"

#include "../p12-euler/triangularnumbers.h"
#include "../p12-euler/triangularnumbers.cpp"

class TriangularNumbersTest : public testing::Test
{
public:
	TriangularNumbers tri;
};



TEST(TriangularNumbersExists, ClassExists) {
	TriangularNumbers tri;
}


TEST_F(TriangularNumbersTest, GivesBackZeroOnZeroCall)
{

	ASSERT_EQ(tri.get_triangular(0), 0);

}

TEST_F(TriangularNumbersTest, GivesBackCorrectTriangular)
{
	ASSERT_EQ(tri.get_triangular(7), 28);
	ASSERT_EQ(tri.get_triangular(6), 21);
}
