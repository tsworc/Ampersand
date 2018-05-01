#pragma once
//
//Following tutorial here at
//http://www.dreamincode.net/forums/topic/10157-data-structures-in-c-tutorial/
//
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

namespace Collections
{
	class CL_List
	{
	private:
		struct node
		{
			int data;
			node *link;
		};
		struct node *p;
	public:
		CL_List();
		CL_List(CL_List& l);
		~CL_List();
		void add(int num);
		void del();
		void addatbeg(int num);
		void display();
		void gotoxy(int x, int y);
		void slideshow(float, int, int);
		int count();
		void wait(float f);
		bool operator ==(CL_List);
		bool operator !=(CL_List);
		//void operator =(CL_List); //?
	};
}