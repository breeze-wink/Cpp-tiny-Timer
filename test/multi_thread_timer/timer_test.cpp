#include <iostream>
#include <functional>
#include "timer.h"

using namespace breeze::utility;

void print(int x, std::string y)
{
    std::cout << x << " " << y << std::endl;
}

int main()
{
    Timer t1(4);
    Timer t2(6);
    // std::function<void()> func = print;
    t1.start(3000, print, 1, "print t1");
    t2.start(2000, print, 2, "print t2");

    getchar();
    return 0;
}