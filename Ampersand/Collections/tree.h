//
//Following tutorial here at
//http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
//

#pragma once
#include <iostream>
using namespace std;

#define YES 1
#define NO 0

namespace Collections
{
	class tree
	{
	private:
		struct leaf
		{
			int data;
			leaf *l;
			leaf *r;
		};
		struct leaf *p;
		void count_in(leaf *q, int &sum);
	public:
		tree();
		~tree();
		void destruct(leaf *q);
		tree(tree &t);
		void findparent(int n, int &found, leaf *&parent);
		void findfordel(int n, int &found, leaf *&parent, leaf *&x);
		void add(int n);
		void transverse();
		void in(leaf *q);
		void pre(leaf *q);
		void post(leaf *q);
		void del(int n);
		int count();
	};
}