#ifdef UNIT_TEST
#include "unity.h"

void test_foo1()
{
	// This test should pass.
	TEST_ASSERT_EQUAL_INT(1, 1);
}

void test_foo2()
{
	// This test should pass.
	TEST_ASSERT_EQUAL_INT(1, 1);
}

int main()
{
	UNITY_BEGIN();  // start unit teseting

	// Both tests should pass.
	// So this test directory "foo" should pass.
	RUN_TEST(test_foo1);
	RUN_TEST(test_foo2);

	UNITY_END();    // stop unit testing
}

#endif
