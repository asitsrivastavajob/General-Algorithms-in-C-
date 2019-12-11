#pragma once
#include <vector>
#include <thread>

class thread_guard
{
	std::thread& m_thread;
public:
	explicit thread_guard(std::thread& _obj) :m_thread(_obj) {}
	~thread_guard()
	{
		if (m_thread.joinable())
		{
			m_thread.join();
		}
	}
	thread_guard(thread_guard & const) = delete;
	thread_guard & operator = (thread_guard & const) = delete;
};