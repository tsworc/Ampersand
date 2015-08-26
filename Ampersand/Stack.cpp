#include "Headers/Stack.h"


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