#pragma once
//
//Following tutorial here at
//http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
//
#include <iostream>
using namespace std;

namespace Collections
{
	class LStack
	{
	private:
		struct node
		{
			int data;
			node* link;
		};
		struct node* top;
	public:
		LStack();
		void push(int num);
		int pop();
		int count();
		~LStack();
	};
}