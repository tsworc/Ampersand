#pragma once
#include <iostream>
using namespace std;
#define MAX 10 //Max stack size

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

