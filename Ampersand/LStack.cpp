#include "LStack.h"
#include "Catch.hpp"

LStack::LStack()
{
	top = NULL;
}

LStack::~LStack()
{
	if (top == NULL)
		return;

	node *tmp;
	while (top != NULL)
	{
		//move top forward and delete tmp
		tmp = top;
		top = top->link;
		delete tmp;
	}
}

//create a node behind top
void LStack::push(int num)
{
	node *tmp;
	tmp = new node;
	if (tmp == NULL)
		cout << "\nStack is full!";
	tmp->data = num;
	tmp->link = top;
	top = tmp;
}

int LStack::pop()
{
	if (top == NULL)
	{
		cout << "\nStack is empty";
		return -1;
	}
	node *tmp;
	int n;
	tmp = top;
	n = top->data;
	top = top->link;
	delete tmp;
	return n;
}

int LStack::count()
{
	node *q;
	int c = 0;
	for (q = top; q != NULL; q = q->link)
		++c;
	return c;
}

SCENARIO("LStacks can Push and Count")
{
	LStack stack;
	GIVEN("A stack with 5, 8, and 7")
	{
		stack.push(5);
		stack.push(8);
		stack.push(7);
		REQUIRE(stack.count() == 3);
		WHEN("5 things are pushed")
		{
			int n;
			for (int i = 0; i < 5; ++i)
			{
				n = i * 5;
				CAPTURE(n)
				stack.push(n);
			}
			THEN("Count = 8")
			{
				REQUIRE(stack.count() == 8);
			}
		}
		WHEN("The stack is popped")
		{
			THEN("We get 7 and count is 2")
			{
				int result;
				result = stack.pop();
				CAPTURE(result);
				REQUIRE(result == 7);
				CAPTURE(stack.count())
				REQUIRE(stack.count() == 2);
			}
		}
	}
}