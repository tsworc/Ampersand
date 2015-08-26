#pragma once
#include "Stack.h"
class StackTester
{
private:
	Stack _stack;
public:
	StackTester()
	{
		_stack = Stack();
	}
	~StackTester(){
	}
	int Test()
	{
		_stack.push(3);
		cout << "3 is Pushed\n";
		_stack.push(10);
		cout << "10 is Pushed\n";
		_stack.push(1);
		cout << "1 is Pushed\n";

		cout << _stack.pop() << " is Popped\n";
		cout << _stack.pop() << " is Popped\n";
		cout << _stack.pop() << " is Popped\n";
		return 0;
	}
};