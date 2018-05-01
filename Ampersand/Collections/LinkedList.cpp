#include "LinkedList.h"

namespace Collections
{
	LinkedList::LinkedList()
	{
		p = NULL;
	}


	LinkedList::~LinkedList()
	{
		node *q;
		if (p == NULL)
			return;
		//O(n)
		while (p != NULL)
		{
			//store the next node
			q = p->link;
			//delete this node
			delete p;
			//move the head to the next node
			p = q;
		}
	}

	void LinkedList::append(int num)
	{
		node *q, *t;

		//O(n)
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
		//O(1)
		q = new node;
		q->data = num;
		q->link = p;
		p = q;
	}

	void LinkedList::add_after(int c, int num)
	{
		//TODO: Finish http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
		//q is current, t will be our new node
		node *q, *t;
		int i;
		//start a chain at the head, p
		//O(n)
		for (i = 0, q = p; i < c; ++i)
		{
			q = q->link;
			if (q == NULL)
			{
				cout << "\nThere are less than " << c << " elements";
				return;
			}
		}

		t = new node;
		t->data = num;
		t->link = q->link;
		q->link = t;
	}

	//search delete
	void LinkedList::del(int num)
	{
		node *q, *r;
		//set q to the head
		q = p;
		if (q->data == num) //found the num
		{
			//move head to the next node
			p = q->link;
			delete q;
			return;
		}

		r = q;
		//O(n)
		while (q != NULL)
		{
			if (q->data == num)
			{
				//if r != q, this bridges the gap
				r->link = q->link;
				delete q;
				return;
			}

			r = q;
			q = q->link;
		}

		cout << "Num was not found in the Linked List" << endl;
	}

	int LinkedList::element_at(int c)
	{
		node *q;
		int i = 0;
		//O(n)
		for (q = p; q != NULL; q = q->link)
		{
			if (i == c)
				return q->data;
			++i;
		}
		cout << "Element at " << c << " is out of bounds!" << endl;
		return NULL;
	}

	void LinkedList::display()
	{
		node *q;
		cout << endl;
		//O(n)
		for (q = p; q != NULL; q = q->link)
		{
			cout << endl << q->data;
		}
	}

	int LinkedList::count()
	{
		node *q;
		int c = 0;
		//O(n)
		for (q = p; q != NULL; q = q->link)
			++c;

		return c;
	}
}