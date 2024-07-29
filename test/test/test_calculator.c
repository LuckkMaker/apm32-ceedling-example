#include "unity.h"
#include "calculator.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addition(void)
{
    TEST_ASSERT_EQUAL_UINT32(5, addition(2,3));
}
void test_substraction(void)
{
    TEST_ASSERT_EQUAL_UINT32(3, substraction(6,3));
}
void test_multiplication(void)
{
    TEST_ASSERT_EQUAL_UINT32(6, multiplication(2,3));
}
void test_division(void)
{
    TEST_ASSERT_EQUAL_UINT32(4, division(8,2));
}
