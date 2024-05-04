#include <cstdio>
#include <functional>
#include <iostream>
#include <thread>
#include <atomic>
#include "time_manager.h"

using namespace breeze::timer;
using namespace breeze::utility;

int a = 2;
int b = 3;
std::atomic<bool> isfinish(false);
void func(int& x)
{
    x *= 2;
    std::cout << x << std::endl;
}

int main()
{
    auto TM = Singleton<TimeManager>::instance();
    TM -> schedule(2000, 10, func, std::ref(a));
    TM -> schedule(3000, 7, func, std::ref(b));

    std::thread TM_thread([&]{
        while(true)
        {
            if (isfinish.load())
            {
                break;
            }
            TM -> update();
        }
    });

    getchar();
    isfinish.store(true);
    TM_thread.join();
    return 0;
}