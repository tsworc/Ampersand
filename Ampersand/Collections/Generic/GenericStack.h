#pragma once
#include <iostream>
#include "Catch.hpp"
using namespace std;

namespace Collections
{
	template<class T> class GenericStack
	{
	private:
		struct node
		{
			T data;
			node *next;
		};
		struct node *top;
	public:
		GenericStack();
		~GenericStack();
		void push(T data);
		T pop();
		int count();
	};
	template <class T>GenericStack<T>::GenericStack()
	{
		top = NULL;
	}

	template <class T>GenericStack<T>::~GenericStack()
	{
		if (top == NULL)
			return;
		node *q;
		while (top != NULL)
		{
			q = top;
			top = top->next;
			delete q;
		}
	}

	template <class T> void GenericStack<T>::push(T data)
	{
		node *tmp;
		tmp = new node;
		if (tmp == NULL)
		{
			cout << "Stack is full!" << endl;
			return;
		}
		tmp->data = data;
		tmp->next = top;
		top = tmp;
	}

	template <class T> T GenericStack<T>::pop()
	{
		if (top == NULL)
		{
			cout << "Stack is empty!" << endl;
			return NULL;
		}
		node *q;
		q = top;
		T data = top->data;
		top = top->next;
		delete q;
		return data;
	}

	template <class T> int GenericStack<T>::count()
	{
		if (top == NULL)
		{
			return 0;
		}
		node *q;
		q = top;
		int c = 1;
		while (q->next != NULL)
		{
			q = q->next;
			++c;
		}
		return c;
	}
}