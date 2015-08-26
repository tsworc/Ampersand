#pragma once
#include <iostream>
#include "Queue.h"
using namespace std;

class QueueTester
{
private:
	Queue _queue;
public:
	QueueTester()
	{
		_queue = Queue();
	}
	~QueueTester()
	{

	}
	int Test()
	{
		int data[5] = { 32, 23, 45, 99, 24 };
		cout << "Queue before adding Elements: ";
		_queue.display();
		cout << endl << endl;

		for (int iter = 0; iter < 5; ++iter)
		{
			_queue.add(data[iter]);
			cout << "Addition Number: " << (iter + 1) << " : ";
			_queue.display();
			cout << endl;
		}

		cout << endl;
		cout << "Queue after adding Elements: ";
		_queue.display();
		cout << endl << endl;

		for (int iter = 0; iter < 5; ++iter)
		{
			_queue.del();
			cout << "Deletion Number : " << (iter + 1) << " : ";
			_queue.display();
			cout << endl;
		}

		return 0;
	}
};