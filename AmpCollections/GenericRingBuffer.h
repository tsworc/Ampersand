#pragma once
#include <iostream>
using namespace std;
//A ring buffer follows First in First out.
//Implementing a double linked list allows it to resize.

namespace Collections
{
	template <class T> class GenericRingBuffer
	{
	private:
		struct node
		{
			T data;
			node *next;
			node *prev;
		};
		node *front;
		node *back;
	public:
		GenericRingBuffer();
		~GenericRingBuffer();
		void enqueue(T data);
		T dequeue();
		int count();
	};

	template <class T> GenericRingBuffer<T>::GenericRingBuffer()
	{
		front = NULL;
		back = NULL;
	}


	template <class T> GenericRingBuffer<T>::~GenericRingBuffer()
	{
		if (front == NULL)
			return;
		node *q;
		q = front;
		while (q != back)
		{
			front = q;
			q = q->next;
			delete front;
		}
		delete back;
	}

	template <class T> void GenericRingBuffer<T>::enqueue(T data)
	{
		node *tmp;
		tmp = new node;
		if (tmp == NULL)
		{
			cout << "Ring Buffer overflow." << endl;
			return;
		}
		tmp->data = data;
		if (front == NULL)
		{
			tmp->next = tmp;
			front = back = tmp;
			return;
		}
		tmp->next = front;
		tmp->prev = back;
		back->next = tmp;
		back = tmp;
	}

	template <class T> T GenericRingBuffer<T>::dequeue()
	{
		T element = NULL;
		if (front == NULL || back == NULL)
		{
			cout << "Ring Buffer Underflow." << endl;
			return element;
		}
		node *tmp;
		tmp = front;
		element = front->data;
		if (front == back)
		{
			delete front;
			front = NULL;
			back = NULL;
		}
		else
		{
			front = front->next;
			back->next = front;
			front->prev = back;
			delete tmp;
		}
		return element;
	}

	template <class T> int GenericRingBuffer<T>::count()
	{
		if (front == NULL)
		{
			return 0;
		}
		node *tmp;
		tmp = front;
		int c = 1;
		while (tmp->next != front)
		{
			++c;
			tmp = tmp->next;
		}
		return c;
	}
}