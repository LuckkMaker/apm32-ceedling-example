/**
 * @file calculator.c
 * @author David LEVAL (dleval@dle-dev.com)
 * @version 1.0
 * @date 2021-05-17
 * @copyright Copyright (c) 2021
 */
#include "calculator.h"
uint32_t addition(uint32_t a, uint32_t b)
{
    if (a > 1)
    return a + b;
    else
    return 0;
}
uint32_t substraction(uint32_t a, uint32_t b)
{
    return a - b;
}
uint32_t multiplication(uint32_t a, uint32_t b)
{
    return a * b;
}
uint32_t division(uint32_t a, uint32_t b)
{
    return a / b;
}