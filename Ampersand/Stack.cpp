#include "Stack.h"
#include "Catch.hpp"

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

SCENARIO("Stacks can insert, delete, and count. They have a maximum of 10 integers.")
{
	Stack stack;
	GIVEN("A stack of 5 numbers")
	{
		stack.push(10);
		stack.push(30);
		stack.push(90);
		stack.push(120);
		stack.push(150);
		WHEN("2 more are added")
		{
			stack.push(180);
			stack.push(210);
			THEN("count() == 7")
			{
				REQUIRE(stack.count() == 7);
			}
		}
		WHEN("2 are deleted")
		{
			stack.pop();
			stack.pop();
			THEN("count() == 3")
			{
				REQUIRE(stack.count() == 3);
			}
		}
		WHEN("6 are deleted")
		{
			for (int i = 0; i < 6; ++i)
				stack.pop();
			THEN("count() == 0")
			{
				REQUIRE(stack.count() == 0);
			}
		}
		WHEN("6 are added")
		{
			for (int i = 0; i < 6; ++i)
				stack.push(i * 17);
			THEN("count() == 10")
			{
				REQUIRE(stack.count() == 10);
			}
		}
	}
}