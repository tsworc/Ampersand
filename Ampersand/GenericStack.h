#pragma once
#include <iostream>
using namespace std;

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

