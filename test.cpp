#include <math.h>
#include <chrono>
#include <iostream>

int main( int argc, char * argv[] ) {

    int x = 4096;
    int a = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000000; i++)
    {
        if ( x * x == 16777216)
        {
            a++;
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    a = 0;
    begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000000; i++)
    {
        if ( x == sqrt(16777216))
        {
            a++; 
        }
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    //engine(FPS);
    return 0;
}
