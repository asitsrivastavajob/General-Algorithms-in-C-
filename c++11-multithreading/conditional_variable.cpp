// c++11-multithreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include "thread_guard.h"
using namespace std;
mutex m1,m2,m;
int g_Distance = 0;

condition_variable g_notify_1;
condition_variable g_notify_2;

void thread_read_buffer()
{
	while (true)
	{
		unique_lock<mutex> read_ulock(m1);
		g_notify_2.wait(read_ulock, [] { return (g_Distance == 0); });
		cout << "Distance travelled :: "<< g_Distance << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		g_Distance++;
		if(g_Distance == 10)
			g_notify_1.notify_one();
	}
}

void thread_write_buffer()
{	
	while (true)
	{
		unique_lock<mutex> write_ulock(m1);
		g_notify_1.wait(write_ulock, [] { return (g_Distance == 10); });
		cout << "Return Distance travelled :: " << g_Distance << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		g_Distance++;
		if (g_Distance == 10)
			g_notify_2.notify_one();
	}
}

int main()
{
	thread th1(thread_read_buffer);
	thread th2(thread_write_buffer);
	
	thread_guard t1(th1);
	thread_guard t2(th2);
		
    return 0;
}

