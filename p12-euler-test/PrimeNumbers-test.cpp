#include "pch.h"

#include "../p12-euler/primenumbers.h"


class PrimeNumberTesting : public testing::Test
{
public:
	PrimeNumbers primenumbers;
};


TEST_F(PrimeNumberTesting, GetPrimeNumberAtPosition)
{
	ASSERT_EQ(primenumbers.get_prime(10), 29);
	ASSERT_EQ(primenumbers.get_prime(12), 37);
	ASSERT_EQ(primenumbers.get_prime(0), 0);

}
