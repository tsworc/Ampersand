#include "Collections\LStack.h"

namespace Collections
{
	LStack::LStack()
	{
		top = NULL;
	}

	LStack::~LStack()
	{
		if (top == NULL)
			return;

		//O(n)
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
		//O(1)
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
		//O(1)
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
		//O(n)
		node *q;
		int c = 0;
		for (q = top; q != NULL; q = q->link)
			++c;
		return c;
	}
}