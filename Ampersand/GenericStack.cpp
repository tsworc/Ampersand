#include "GenericStack.h"
#include "Catch.hpp"


template <class T>GenericStack<T>::GenericStack()
{
	top = NULL;
}

template <class T>GenericStack<T>::~GenericStack()
{
	if (top == NULL)
		return;
	node *q;
	while (top != NULL)
	{
		q = top;
		top = top->next;
		delete q;
	}
}

template <class T> void GenericStack<T>::push(T data)
{
	node *tmp;
	tmp = new node;
	if (tmp == NULL)
	{
		cout << "Stack is full!" << endl;
		return;
	}
	tmp->data = data;
	tmp->next = top;
	top = tmp;
}

template <class T> T GenericStack<T>::pop()
{
	if (top == NULL)
	{
		cout << "Stack is empty!" << endl;
		return NULL;
	}
	node *q;
	q = top;
	T data = top->data;
	top = top->next;
	delete q;
	return data;
}

template <class T> int GenericStack<T>::count()
{
	if (top == NULL)
	{
		return 0;
	}
	node *q;
	q = top;
	int c = 1;
	while (q->next != NULL)
	{
		q = q->next;
		++c;
	}
	return c;
}

SCENARIO("Generic Stacks can store any data type. They can push, pop, and count.")
{
	GIVEN("A generic stack of strings [\"Run\", \"Jump\", \"Dash Forward\", \"Dash Back\"]")
	{
		GenericStack<char *> stack;
		stack.push("Run");
		stack.push("Jump");
		stack.push("Dash Forward");
		stack.push("Dash Back");
		REQUIRE(stack.count() == 4);
		WHEN("We pop twice")
		{
			char * a = stack.pop();
			char * b = stack.pop();
			THEN("we get \"Dash Back\", \"Dash Forward\" and count is 2")
			{
				CAPTURE(a);
				CAPTURE(b);
				REQUIRE(strcmp(a, "Dash Back") == 0);
				REQUIRE(strcmp(b, "Dash Forward") == 0);
				REQUIRE(stack.count() == 2);
				cout << a << endl;
				cout << b << endl;
			}
		}
		WHEN("We pop 5 times")
		{
			for (int i = 0; i < 5; ++i)
				stack.pop();
			THEN("Count is 0")
			{
				REQUIRE(stack.count() == 0);
			}
		}
	}
}