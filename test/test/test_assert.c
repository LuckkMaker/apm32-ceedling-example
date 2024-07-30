#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_assert(void)
{
    TEST_ASSERT_EQUAL_INT32(1, 1);
    TEST_ASSERT_EQUAL_INT64(1, 1);
    TEST_ASSERT_EQUAL_UINT8(1, 1);
    TEST_ASSERT_EQUAL_UINT16(1, 1);
    TEST_ASSERT_EQUAL_UINT32(1, 1);
    TEST_ASSERT_EQUAL_UINT64(1, 1);
    TEST_ASSERT_EQUAL_PTR(&test_assert, &test_assert);
    TEST_ASSERT_EQUAL_STRING("test_assert", "test_assert");
    TEST_ASSERT_EQUAL_MEMORY("test_assert", "test_assert", 12);
    TEST_ASSERT_NOT_EQUAL(0, 1);
    TEST_ASSERT_NOT_EQUAL_INT(0, 1);
    TEST_ASSERT_NOT_EQUAL_UINT(0, 1);
    TEST_ASSERT_NOT_EQUAL_HEX8(0x00, 0x01);
    TEST_ASSERT_NOT_EQUAL_HEX16(0x00, 0x01);
    TEST_ASSERT_NOT_EQUAL_HEX32(0x00, 0x01);
    TEST_ASSERT_NOT_EQUAL_HEX64(0x00, 0x01);
}
