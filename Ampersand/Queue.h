#pragma once

#include <iostream>
using namespace std;

#define MAX 5 //Max queue size

class Queue
{
private:
	int t[MAX];
	int al; //addition end
	int dl; //deletion end
public:
	Queue();
	~Queue();
	void del();
	void add(int a);
	void display();
};