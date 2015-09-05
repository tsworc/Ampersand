#pragma once
//
//Following tutorial here at
//http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
//
#include <iostream>
using namespace std;

namespace Collections
{
	class LQueue
	{
	private:
		struct node
		{
			int data;
			node *link;
		};
		struct node *front;
		struct node *rear;
	public:
		LQueue();
		~LQueue();
		void add(int num);
		int del();
		int count();
	};
}