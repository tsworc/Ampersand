#include "DL_List.h"
#include "Catch.hpp"

DL_List::DL_List()
{
	p = NULL;
}

DL_List::DL_List(DL_List &t)
{
	node *x;
	x = t.p;
	if (x == NULL)
	{
		p = NULL;
		return;
	}
	for (int i = 1; 1 <= t.count(); ++i)
	{
		add(x->data);
		x = x->next;
	}
}

DL_List::~DL_List()
{
	if (p == NULL)
	{
		return;
	}
	node *q, *t;
	q = p;
	t = p;
	while (q->next != t)
	{
		p = q;
		q = q->next;
		delete p;
	}
	p = q;
	delete p;
}

void DL_List::add(int num)
{
	//first to the party?
	if (p == NULL)
	{
		node *q;
		q = new node;
		q->data = num;
		q->next = q;
		q->prev = q;
		p = q;
		return;
	}
	node *q;
	q = p;
	while (q->next != p)
		q = q->next;
	node *t;
	t = new node;
	t->data = num;
	t->next = p;
	t->prev = q;
	q->next = t;
	p->prev = t;
}

void DL_List::add_at_beg(int num)
{
	if (p == NULL)
	{
		node *q;
		q = new node;
		q->data = num;
		q->next = q;
		q->prev = q;
		p = q;
		return;
	}
	node *q;
	q = p;
	node * t;
	t = new node;
	t->data = num;
	t->next = q;
	t->prev = q->prev;
}