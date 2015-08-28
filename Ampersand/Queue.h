#pragma once

#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 5 //Max queue size

class Queue
{
private:
	int t[MAX_QUEUE_SIZE];
	int al; //addition end
	int dl; //deletion end
public:
	Queue();
	~Queue();
	void del();
	void add(int a);
	void display();
	int count();
};