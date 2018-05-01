#include "Stack.h"

namespace Collections{
	Stack::Stack()
	{
		top = -1; //Sets top location to -1 to indicate the stack is empty
	}


	Stack::~Stack()
	{
	}

	void Stack::push(int a)
	{
		top++;
		//O(1)
		if (top < MAX) //space available?
		{
			arr[top] = a; //place input on top
		}
		else
		{
			cout << "The Stack is Full!" << endl;
			top--;
		}
	}

	int Stack::pop() //Delete item. Return the deleted item.
	{
		//O(1)
		if (top == -1)
		{
			cout << "This Stack is empty!" << endl;
			return NULL;
		}
		else
		{
			int data = arr[top]; //get topmost value
			arr[top] = NULL; //set original location to null
			top--;
			return data;
		}
	}

	int Stack::count()
	{
		//O(1)
		return top + 1;
	}
}