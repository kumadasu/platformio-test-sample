#ifdef UNIT_TEST
#include "unity.h"
#include "Sample.h"
#include <stdio.h>

Sample *sample;
int counter = 100;

// setUp() runs before each RUN_TEST().
void setUp(void)
{
	counter = 1;
	sample = new Sample();
	printf("Setup: counter=%d.  ", counter);
}

// tearDown() runs after each RUN_TEST().
void tearDown(void)
{
	counter++;
	delete sample;
	printf("Tear down: counter=%d.  ", counter);
}

void test_foo1()
{
	// This test should pass.
	TEST_ASSERT_EQUAL_INT(counter, 1);
}

void test_foo2()
{
	// This test should pass.
	TEST_ASSERT_EQUAL_INT(sample->sampleMethod(counter), 2);
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
