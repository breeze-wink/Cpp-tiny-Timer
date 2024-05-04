#pragma once
#include <chrono>
#include <functional>
#include <atomic>
#include <thread>

//基于多线程的定时器
namespace breeze 
{ 
    namespace utility
    {
        class Timer
        {
        public:
            Timer();
            Timer(int repeat);
            ~Timer();

            template<typename F, typename ...Args>
            void start(int milliseconds, F&& func, Args&&... args);
            void stop();
        private:
            std::thread m_thread;
            std::atomic<bool> m_active;
            std::function<void()> m_func;
            int m_period;
            int m_repeat;
        };

        template<typename F, typename ...Args>
        void Timer::start(int milliseconds, F&& func, Args&&...args)
        {
            if (m_active.load())
            {
                return;
            }
            m_period = milliseconds;
            m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
            m_active.store(true); // 设置为真(上锁)
            m_thread = std::thread([&]{
                if (m_repeat < 0) // 无限计数
                {
                    while (m_active.load())
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(m_period));
                        if (!m_active.load())
                        {
                            return; // 因其他原因被停止了
                        }
                        m_func();
                    }
                }
                else
                {
                    while (m_repeat --)
                    {
                        if (!m_active.load())
                        {
                            return;
                        }
                        std::this_thread::sleep_for(std::chrono::milliseconds(m_period));
                        if (!m_active.load())
                        {
                            return;
                        }
                        m_func();
                    }
                }
            });
            m_thread.detach();
        }
    } 
}