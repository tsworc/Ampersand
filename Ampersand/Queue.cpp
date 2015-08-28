#include "Queue.h"
#include "Catch.hpp"

Queue::Queue()
{
	al = -1;
	dl = -1;
}


Queue::~Queue()
{
}

void Queue::del()
{
	int tmp;
	if (dl == -1)
	{
		cout << "Queue is Empty";
	}
	else
	{
		//loop from front to add end
		for (int j = 0; j <= al; ++j)
		{
			if ((j + 1) <= al) // is there a next element?
			{
				tmp = t[j + 1]; //store next element
				t[j] = tmp; //move next element forward
			}
			else //this is the last element
			{
				al--; //move addition end forward
				if (al == -1) //empty?
					dl = -1; //empty!
				else
					dl = 0; //move deletion end to front
			}
		}
	}
}

void Queue::add(int item)
{
	if (dl == -1 && al == -1) //empty?
	{
		dl++;
		al++;
		//set add and delete ends to the front
	}
	else
	{
		al++; //increment the add end
		if (al == MAX_QUEUE_SIZE) //out of bounds?
		{
			cout << "Queue is Full\n";
			al--;
			return;
		}
	}
	t[al] = item;
}

int Queue::count()
{
	return al + 1;
}

void Queue::display()
{
	if (dl != -1) //not empty?
	{
		for (int iter = 0; iter <= al; ++iter) //loop from start to add end
			cout << t[iter] << " ";
	}
	else
	{
		cout << "EMPTY";
	}
}

SCENARIO("Queues can add, del, and count")
{
	int data[5] = { 32, 23, 45, 99, 24 };
	Queue _queue;
	REQUIRE(_queue.count() == 0);

	for (int iter = 0; iter < 5; ++iter)
		_queue.add(data[iter]);
	REQUIRE(_queue.count() == 5);

	for (int iter = 0; iter < 5; ++iter)
		_queue.del();
	REQUIRE(_queue.count() == 0);
}