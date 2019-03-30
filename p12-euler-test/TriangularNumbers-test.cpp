#include "pch.h"

#include "../p12-euler/TriangularNumbers.h"
#include "../p12-euler/TriangularNumbers.cpp"

class TriangularNumbersTest : public testing::Test
{
public:
	TriangularNumbers tri;
};



TEST(TriangularNumbersExists, ClassExists) {
	TriangularNumbers tri;
}


TEST_F(TriangularNumbersTest,GivesBackZeroOnZeroCall)
{

	ASSERT_EQ(tri.get_triangular(0), 0);

}