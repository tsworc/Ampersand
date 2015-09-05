#include "Collections\CL_List.h"

namespace Collections
{
	CL_List::CL_List()
	{
		p = NULL;
	}

	CL_List::CL_List(CL_List& l){
		node *x;
		p = NULL;
		x = l.p;
		if (x == NULL)
			return;
		//O(n)
		for (int i = 1; i <= l.count(); ++i)
		{
			//create a node with identical data
			add(x->data);
			//move forward
			x = x->link;
		}
	}

	CL_List::~CL_List()
	{
		node *q, *t;
		q = p;
		t = p;
		if (p == NULL)
		{
			return;
		}
		//delete until we reach the point that loops back to the head
		//O(n)
		while (q->link != t)
		{
			p = q;
			q = q->link;
			delete p;
		}
		p = q;
		delete p;
	}

	void CL_List::add(int num)
	{
		if (p == NULL)
		{
			node *q;
			q = new node;
			q->data = num;
			//this is the head, create a loop
			q->link = q;
			p = q;
			return;
		}
		node *q;
		q = p;
		//O(n)
		while (q->link != p)
			q = q->link;
		node *t;
		t = new node;
		t->data = num;
		t->link = p;
		q->link = t;
	}

	void CL_List::display()
	{
		if (p == NULL){
			cout << "CL_List is Empty!\n";
			return;
		}
		node *q;
		q = p;
		//O(n)
		for (int i = 1; i <= this->count(); ++i)
		{
			cout << q->data << endl;
			q = q->link;
		}
	}

	int CL_List::count()
	{
		node *q;
		q = p;
		int c = 0;
		if (p == NULL)
			return 0;
		else
			++c;
		//O(n)
		while (q->link != p)
		{
			++c;
			q = q->link;
		}
		return c;
	}

	void CL_List::del()
	{
		if (p == NULL)
			return;
		if (p->link == p)
		{
			p = NULL;
		}
		else
		{
			node *q;
			q = p;
			//O(n)
			while (q->link != p)
				q = q->link;

			//connect to the node after the head
			q->link = p->link;
			q = p;
			//?
			p = (q->link == NULL ? NULL : p->link);
			delete q;
		}
	}

	void CL_List::addatbeg(int num)
	{
		node *q, *t;
		q = p;
		//O(n)
		while (q->link != p)
			q = q->link;

		t = new node;
		t->data = num;
		t->link = p;
		q->link = t;
		p = t;
	}

	void CL_List::gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void CL_List::slideshow(float dlay, int x, int y)
	{
		if (p == NULL)
		{
			gotoxy(x, y);
			cout << "EMPTY LIST!\n";
			return;
		}
		node *q;
		q = p;
		while (!_kbhit())
		{
			gotoxy(x, y);
			cout << "               ";
			gotoxy(x, y);
			cout << q->data;
			wait(dlay);
			q = q->link;
		}
	}

	void CL_List::wait(float t)
	{
		long time = GetTickCount() + (t * 1000L);
		while (GetTickCount() <= time)
		{
			/*	Wait	*/
		}
	}

	bool CL_List::operator==(CL_List t)
	{
		//both null?
		if (t.p == NULL && p == NULL)
			return 1;

		if (t.count() != this->count())
			return 0;

		node *q;
		q = p;
		bool flag;
		flag = 1;
		node *a;
		a = t.p;
		for (int i = 1; i <= count(); ++i)
		{
			if (a->data != q->data)
				flag = 0;
			a = a->link;
			q = q->link;
		}
		if (a->data != q->data)
			flag = 0;
		return flag;
	}

	bool CL_List::operator!=(CL_List t)
	{
		return !(this->operator==(t));
	}
}