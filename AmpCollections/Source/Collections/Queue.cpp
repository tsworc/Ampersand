#include "Collections\Queue.h"

namespace Collections{
	Queue::Queue()
	{
		al = -1;
		dl = -1;
	}


	Queue::~Queue()
	{
	}

	//Shouldnt this return the int?
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
			//O(n)
			for (int j = 0; j <= al; ++j)
			{
				if ((j + 1) <= al) // is there a next element?
				{
					tmp = t[j + 1]; //store next element
					t[j] = tmp; //move next element back
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
		//O(1)
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
		//O(n)
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
}