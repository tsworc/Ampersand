#pragma once
#include <iostream>
using namespace std;

namespace Collections
{
	class DL_List
	{
	private:
		struct node
		{
			int data;
			node *next;
			node *prev;
		};
		struct node *p;
	public:
		DL_List();
		DL_List(DL_List &t);
		~DL_List();
		void add(int num);
		void add_at_beg(int num);
		void del();
		void display(int type);
		int count();
		int element_at(int index);
		bool operator==(DL_List);
		bool operator!=(DL_List);

	};
}