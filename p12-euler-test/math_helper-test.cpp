#include "pch.h"

#include "../p12-euler/math_helper.h"
#include "../p12-euler/math_helper.cpp"


namespace hp = helper;


TEST(PowerFunctionTest, ReturnsZeroOnZeroBaseCall)
{
	ASSERT_EQ(hp::LLPow(0, 10), 0);

}

TEST(PowerFunctionTest, ReturnsOneOnZeroExponentCall)
{
	ASSERT_EQ(hp::LLPow(1, 0), 1);
}


TEST(PowerFunctionTest, ReturnsZeroOnZeroBaseZeroExponentCall)
{
	ASSERT_EQ(hp::LLPow(0, 0), 0);
}


TEST(PowerFunctionTest, ReturnNumberOnExponentOneCall)
{
	unsigned long long arbitrary_number = 333;
	ASSERT_EQ(hp::LLPow(arbitrary_number, 1), arbitrary_number);
}


TEST(PowerFunctionTest, ReturnsCorrectPow)
{
	unsigned long long arbitrary = 333;
	unsigned long long exponent = 7;
	unsigned long long result = arbitrary * arbitrary *arbitrary *arbitrary *arbitrary * arbitrary *arbitrary;

	ASSERT_EQ(hp::LLPow(arbitrary, exponent), result);
}



