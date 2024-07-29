/**
  * @file    main.c
  * @author  MorroMaker
  * @brief   Main program body for test project
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
#include "main.h"

#ifdef TEST
    #define LOOP
#else
    //#include "stm32f4xx.h"
    #define LOOP while(1)

    //The target will need a main. 
    //Our test runner will provide it's own and call AppMain()
    int main(void)
    {
        return AppMain();
    }
#endif /* TEST */

int AppMain( void )
{
    LOOP
    {

    }
    return 0;
}
