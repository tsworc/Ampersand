#include "LinkedList.h"


LinkedList::LinkedList()
{
	p = NULL;
}


LinkedList::~LinkedList()
{
}

void LinkedList::append(int num)
{
	node *q, *t;

	if (p == NULL)
	{
		p = new node;
		p->data = num;
		p->link = NULL;
	}
	else
	{
		q = p;
		while (q->link != NULL)
			q = q->link;
		t = new node;
		t->data = num;
		t->link = NULL;
		q->link = t;
	}
}

void LinkedList::add_as_first(int num)
{
	node *q;

	q = new node;
	q->data = num;
	q->link = p;
	p = q;
}

void LinkedList::add_after(int c, int num)
{
	//TODO: Finish http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
	/*node *q, *t;
	int i;
	for (int i = 0, q = p; i < c; ++i)
	{
		q = p->link;
		if (q == NULL)
		{
			cout << "\nThere are less than " << c << " elements";
			return;
		}
	}
	*/
}