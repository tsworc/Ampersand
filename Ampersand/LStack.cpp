#include "LStack.h"


LStack::LStack()
{
	top = NULL;
}

//create a node behind top
void LStack::push(int num)
{
	node *tmp;
	tmp = new node;
	if (tmp == NULL)
		cout << "Stack is full!" << endl;
	tmp->data = num;
	tmp->link = top;
	top = tmp;
}

LStack::~LStack()
{
}
