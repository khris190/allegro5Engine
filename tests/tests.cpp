#include <stdio.h>
 #include "tests.hpp"
 
extern "C" void foo()
{
    puts("this function was called from shared lib on runtime");
}

extern "C" void addition(int* i)
{
    for (int j = 0; j < 100000; j++)
    {
        (*i)++;  
    } 
}