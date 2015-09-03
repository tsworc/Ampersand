#include "tree.h"
#include "Catch.hpp"

tree::tree()
{
	p = NULL;
}


tree::~tree()
{
	destruct(p);
}

void tree::destruct(leaf *q){
	if (q != NULL)
	{
		destruct(q->l);
		leaf *right = q->r;
		del(q->data);
		destruct(right);
	}
}

void tree::findparent(int n, int &found, leaf *&parent)
{
	leaf *q;
	found = NO;
	parent = NULL;

	if(p == NULL)
	{
		return;
	}

	q = p;
	while (q != NULL){
		if (q->data == n)
		{
			found = YES;
			return;
		}
		if (q->data > n){
			parent = q;
			q = q->l;
		}
		else
		{
			parent = q;
			q = q->r;
		}
	}
}

void tree::add(int num){
	int found;
	leaf *t, *parent;
	findparent(num, found, parent);
	if (found == YES)
		cout << "\nSuch a node exists!";
	else
	{
		t = new leaf;
		t->data = num;
		t->l = NULL;
		t->r = NULL;
		if (parent == NULL)
			p = t;
		else
		{
			parent->data > num ? parent->l = t : parent->r = t;
		}
	}
}

void tree::transverse()
{
	int c;
	cout << "\n1. In Order\n2. PreOrder\n3. PostOrder\nChoice: ";
	cin >> c;
	switch (c)
	{
	case 1:
		in(p);
		break;
	case 2:
		pre(p);
		break;
	case 3:
		post(p);
		break;
	}
}

void tree::in(leaf *q)
{
	if (q != NULL)
	{
		in(q->l);
		cout << "\t" << q->data << endl;
		in(q->r);
	}
}

void tree::pre(leaf *q)
{
	if (q != NULL)
	{
		cout << "\t" << q->data << endl;
		pre(q->l);
		pre(q->r);
	}
}

void tree::post(leaf *q)
{
	if (q != NULL)
	{
		post(q->l);
		post(q->r);
		cout << "\t" << q->data << endl;
	}
}

void tree::findfordel(int n, int &found, leaf *&parent, leaf *&x)
{
	leaf *q;
	found = 0;
	parent = NULL;
	//x = NULL;
	if (p == NULL)
		return;

	q = p;
	while (q != NULL)
	{
		if (q->data == n)
		{
			found = 1;
			x = q;
			return;
		}
		if (q->data > n)
		{
			parent = q;
			q = q->l;
		}
		else
		{
			parent = q;
			q = q->r;
		}
	}
}

//hibbard delete algorithm
void tree::del(int num)
{
	leaf *parent, *x, *xsucc;
	int found;

	//Empty tree
	if (p == NULL)
	{
		cout << "\nTree is empty.";
		return;
	}
	parent = x = NULL;
	findfordel(num, found, parent, x);
	if (found == 0)
	{
		cout << "\nNode to be deleted was not found.";
		return;
	}

	//if node to be deleted has left and right
	if (x->l != NULL && x->r != NULL)
	{
		//traverse right then as far down left as possible
		//swap this lowest number with x
		parent = x;
		xsucc = x->r;
		while (xsucc->l != NULL)
		{
			parent = xsucc;
			xsucc = xsucc->l;
		}
		x->data = xsucc->data;
		x = xsucc;
	}

	//if node to be deleted has no children
	if (x->l == NULL && x->r == NULL)
	{
		//special case: root node
		if (x == p)
		{
			delete p;
			p = NULL;
			return;
		}
		if (parent->r == x)
			parent->r = NULL;
		else
			parent->l = NULL;
		delete x;
		return;
	}

	//if node only has right node
	if (x->l == NULL && x->r != NULL)
	{
		//special case: root node
		if (x == p)
		{
			p = x->r;
			delete x;
			return;
		}
		if (parent->l == x)
			parent->l = x->r;
		else
			parent->r = x->r;
		delete x;
		return;
	}

	//if node only has left node
	if (x->l != NULL && x->r == NULL)
	{
		//special case: root node
		if (x == p)
		{
			p = x->l;
			delete x;
			return;
		}
		if (parent->r == x)
			parent->r = x->l;
		else
			parent->l = x->l;
		delete x;
		return;
	}
}

int tree::count()
{
	int sum = 0;
	count_in(p, sum);
	return sum;
}
void tree::count_in(leaf *q, int &sum)
{
	if (q != NULL)
	{
		count_in(q->l, sum);
		++sum;
		count_in(q->r, sum);
	}
}

SCENARIO("A tree can add, delete, count, and display in 3 different ways.")
{
	GIVEN("An empty tree")
	{
		tree t;
		int data[] =
		{ 32, 16, 34, 1, 87, 13, 7, 18, 14, 19, 23, 24, 41, 5, 53 };
		WHEN("15 numbers are added.")
		{
			for (int iter = 0; iter < 15; ++iter)
				t.add(data[iter]);
			THEN("Count = 15")
			{
				REQUIRE(t.count() == 15);
			}
			WHEN("Two numbers in the tree are deleted.")
			{
				t.del(16);
				t.del(41);
				THEN("Count = 13")
				{
					REQUIRE(t.count() == 13);
				}
			}
			WHEN("A number not in the tree is deleted.")
			{
				t.del(408);
				THEN("The count remains 15")
				{
					REQUIRE(t.count() == 15);
				}
			}
		}
	}
}