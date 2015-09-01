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
	q = p->prev;
	node * t;
	t = new node;
	t->data = num;
	t->next = p;
	t->prev = q;
	q->next = t;
	p->prev = t;
	p = t;
}

void DL_List::del()
{
	node *q;
	if (p == NULL)
	{
		cout << "Double Link List is empty!" << endl;
		return;
	}
	q = p;
	if (q->next == p)
	{
		p = NULL;
		return;
	}
	else
	{
		//find end
		while (q->next != p)
		{
			q = q->next;
		}
		q->next = p->next;
		q = p;
		p = (q->next == NULL ? NULL : p->next);
		p->prev = q->prev;
		delete q;
	}
}

int DL_List::element_at(int index)
{
	if (p == NULL)
	{
		cout << "DL_List is empty." << endl;
	}
	if (index == 0)
	{
		return p->data;
	}
	//search forward
	node *q;
	int i = 0;
	q = p;
	while (q->next != p)
	{
		q = q->next;
		++i;
		if (i == index)
			return q->data;
	}
	cout << "Index " << index << " is out of range for this DL_List." << endl;
	return NULL;
}

int DL_List::count()
{
	if (p == NULL)
		return 0;
	node *q;
	int c = 1;
	q = p;
	while (q->next != p)
	{
		q = q->next;
		++c;
	}
	return c;
}

void DL_List::display(int type)
{
	if (p == NULL)
	{
		cout << "The Double Linked List is Empty." << endl;
	}
	node *q;
	q = p;
	if (type == 1)
	{
		for (int i = 1; i <= count(); ++i)
		{
			cout << q->data << ", ";
			q = q->next;
		}
	}
	else
	{
		q = q->prev;
		for (int i = 1; i <= count(); ++i)
		{
			cout << q->data << ", ";
			q = q->prev;
		}
	}
	cout << endl;
}

bool DL_List::operator==(DL_List t)
{
	if (t.p == NULL && p == NULL)
		return 1;
	int length = count();
	if (t.count() != length)
		return 0;

	node *q;
	q = p;
	node *a;
	a = t.p;
	bool flag;
	flag = 1;
	for (int i = 1; i < length; ++i)
	{
		if (a->data != q->data)
			flag = 0;
		a = a->next;
		q = q->next;
	}
	if (a->data != q->data)
		flag = 0;
	return flag;
}

bool DL_List::operator!=(DL_List t)
{
	return !(this->operator==(t));
}

SCENARIO("DL_List can add, delete, count, and display in two directions. Size is limited by available memory.")
{
	GIVEN("A DL_List with [45, 64, 73, 2, 1]")
	{
		DL_List list;
		list.add(64);
		list.add(73);
		list.add(2);
		list.add(1);
		list.add_at_beg(45);
		REQUIRE(list.count() == 5);
		cout << "Print list forwards and backwards." << endl;
		list.display(1);
		list.display(0);
		WHEN("2034 is added to the beginning")
		{
			list.add_at_beg(2034);
			THEN("2034 is the first element")
			{
				REQUIRE(list.element_at(0) == 2034);
			}
		}
		WHEN("54, 32, 21, 76 are added to the beggining. And the list deletes twice.")
		{
			list.add_at_beg(54);
			list.add_at_beg(32);
			list.add_at_beg(21);
			list.add_at_beg(76);
			list.del();
			list.del();
			THEN("Count is 7")
			{
				REQUIRE(list.count() == 7);
			}
			THEN("Element at 0 is 32")
			{
				REQUIRE(list.element_at(0) == 32);
			}
			THEN("Element at 1 is 54")
			{
				REQUIRE(list.element_at(1) == 54);
			}
			THEN("Element at 6 is 1")
			{
				REQUIRE(list.element_at(6) == 1);
			}
		}
	}
}