// c++11-multithreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include "thread_guard.h"
using namespace std;


void thread_function()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Hi I am inside thread_function :: "<< " " << this_thread::get_id() << endl;

	}
}

//int main()
//{
//	thread th1(thread_function);
//	thread th2(thread_function);
//	
//	thread_guard t1(th1);
//	thread_guard t2(th2);
//
//	cout << "Main is finished" << endl;
//    return 0;
//}

