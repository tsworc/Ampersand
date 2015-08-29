#pragma once
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};
class LStack
{
private:
	node* top;
public:
	LStack();
	void push(int num);
	~LStack();
};

