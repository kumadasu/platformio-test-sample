#ifdef UNIT_TEST
#include "unity.h"

void test_bar()
{
	// This test should fail.
	TEST_ASSERT_EQUAL_INT(1, 2);
}

int main()
{
	UNITY_BEGIN();  // start unit teseting

	// This test should fail.
	// So this test directory "bar" should fail.
	RUN_TEST(test_bar);

	UNITY_END();    // stop unit testing
}

#endif
