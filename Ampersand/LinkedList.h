#pragma once
#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct node
	{
		int data;
		node *link;
	}*p;
public:
	LinkedList();
	~LinkedList();
	void append(int num);
	void add_as_first(int num);
	void add_after(int c, int num);
	void del(int num);
	int element_at(int c);
	void display();
	int count();
};

