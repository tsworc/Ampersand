#pragma once
//
//Following tutorial here at
//http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
//
#include <iostream>
using namespace std;
#define MAX 10 //Max stack size

namespace Collections
{
	class Stack
	{
	private:
		int arr[MAX]; //contains the data
		int top; //contains the location of topmost data
	public:
		Stack();
		~Stack();
		void push(int input);
		int pop();
		int count();
	};
}