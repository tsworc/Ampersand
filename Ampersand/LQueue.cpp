#include "LQueue.h"
#include "Catch.hpp"

LQueue::LQueue()
{
	front = NULL;
	rear = NULL;
}


LQueue::~LQueue()
{
	if (front == NULL)
	{
		return;
	}

	//O(n)
	node *tmp;
	while (front != NULL)
	{
		//move front forward and delete its trail
		tmp = front;
		front = front->link;
		delete tmp;
	}
}

void LQueue::add(int num)
{
	node *tmp;
	tmp = new node;
	if (tmp == NULL)
	{
		cout << "\nLQueue is full!";
		return;
	}
	//O(1)
	tmp->data = num;
	tmp->link = NULL;
	if (front == NULL)
	{
		rear = front = tmp;
		return;
	}

	rear->link = tmp;
	rear = rear->link;
}

int LQueue::del()
{
	if (front == NULL)
	{
		cout << "\nLQueue is empty.";
		return -1;
	}

	//O(1)
	node *tmp;
	int n;
	tmp = front;
	n = front->data;
	front = front->link;
	delete tmp;
	return n;
}

int LQueue::count()
{
	node *q;
	int c = 0;
	for (q = front; q != NULL; ++q)
	{
		++c;
	}
	return c;
}

SCENARIO("LQueues can add, delete, and count. Only limited by available memory.")
{
	LQueue queue;
	GIVEN("A LQueue with [20, 88, 0, 43030]")
	{
		queue.add(20);
		queue.add(88);
		queue.add(0);
		queue.add(43030);
		REQUIRE(queue.count() == 4);
	}
}