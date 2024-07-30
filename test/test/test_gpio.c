/**
  * @file    test_gpio.c
  * @author  MorroMaker
  * @brief   GPIO test file
  * @attention
  *
  * Copyright (c) 2024 MorroMaker
  * All rights reserved.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *     http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  */

/* Includes ------------------------------------------------------------------*/
#include "unity.h"

#include "mock_apm32f4xx_dal_gpio.h"

/**
 * @brief Setup function for test runner
 * @note setUp() is called by the generated runner before each test case function.
 * Every test file requires this function.
 */
void setUp(void)
{
    // Set up any necessary initialization here
}

/**
 * @brief Teardown function for test runner
 * @note tearDown() is called by the generated runner after each test case function.
 * Every test file requires this function.
 */
void tearDown(void)
{
    // Clean up after each test case
}

void test_DAL_GPIO_WritePin_SetLow(void)
{
    DAL_GPIO_WritePin_Expect(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
    
    DAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
    
    DAL_GPIO_ReadPin_ExpectAndReturn(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
    uint8_t pinState = DAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5);
    
    TEST_ASSERT_EQUAL(GPIO_PIN_RESET, pinState);
}

void test_DAL_GPIO_WritePin_SeHigh(void)
{
    DAL_GPIO_WritePin_Expect(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
    
    DAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
    
    DAL_GPIO_ReadPin_ExpectAndReturn(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
    uint8_t pinState = DAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5);
    
    TEST_ASSERT_EQUAL(GPIO_PIN_SET, pinState);
}
