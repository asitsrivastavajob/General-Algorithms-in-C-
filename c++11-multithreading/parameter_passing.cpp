// c++11-multithreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include "thread_guard.h"
using namespace std;


void thread_function(int& x)
{
	while (true)
	{
		cout << "Hi I am inside thread_function :: " << x << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
	}
}

//int main()
//{
//	int x = 10;
//	thread th1(thread_function, std::ref(x) );
//	thread_guard t1(th1);
//	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//	x = 20;
//	cout << "Main is finished" << endl;
//	cout << "No. of parallel threads possible :: " << std::thread::hardware_concurrency();
//	return 0;
//}

