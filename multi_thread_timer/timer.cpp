#include "timer.h"

using namespace breeze::utility;

Timer::Timer() : m_active(false), m_period(0), m_repeat(-1){}

Timer::Timer(int repeat) : m_active(false), m_period(0), m_repeat(repeat){}

Timer::~Timer()
{
    stop();
}

void Timer::stop()
{
    m_active.store(false);
}