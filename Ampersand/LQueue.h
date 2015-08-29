#pragma once
//
//Following tutorial here at
//http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
//
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *link;
};

class LQueue
{
private:
	node *front;
	node *rear;
public:
	LQueue();
	~LQueue();
	void add(int num);
	int del();
	int count();
};

