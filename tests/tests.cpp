#include <stdio.h>
 #include "tests.hpp"
 
extern "C" void foo()
{
    puts("Hello, I am a shared library");
}