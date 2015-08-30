#pragma once
#include <iostream>
using namespace std;

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
	bool operator==(DL_List);
	bool operator!=(DL_List);
	
};

