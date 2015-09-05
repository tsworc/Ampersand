#include "Catch.hpp"
#include "Header\Collections\CL_List.h"
#include "Header\Collections\DL_List.h"
#include "Header\Collections\Generic\GenericStack.h"
#include "Header\Collections\LQueue.h"
#include "Header\Collections\LStack.h"
#include "Header\Collections\Queue.h"
#include "Header\Collections\Stack.h"
#include "Header\Collections\tree.h"
#include "Header\Collections\LinkedList.h"

SCENARIO("CL_List add, add at beginning, delete, count, and display. It has a copy constructor and operators to check equality.")
{
	Collections::CL_List list;
	list = Collections::CL_List();
	GIVEN("A CL_List with [1,2,3,4]")
	{
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		REQUIRE(list.count() == 4);
		/*WHEN("128 is added to the beginning")
		{
		list.addatbeg(128);
		THEN("Count is 5")
		{
		list.display();
		REQUIRE(list.count() == 5);
		}
		}*/
		WHEN("CL_List deletes")
		{
			list.del();
			THEN("Count is 3")
			{
				REQUIRE(list.count() == 3);
			}
		}
		WHEN("our list = another list")
		{
			Collections::CL_List b = list;
			THEN("the lists are equal")
			{
				REQUIRE(b == list);
			}
		}
	}
}
SCENARIO("DL_List can add, delete, count, and display in two directions. Size is limited by available memory.")
{
	GIVEN("A DL_List with [45, 64, 73, 2, 1]")
	{
		Collections::DL_List list;
		list.add(64);
		list.add(73);
		list.add(2);
		list.add(1);
		list.add_at_beg(45);
		REQUIRE(list.count() == 5);
		WHEN("Print forwards and backwards")
		{
			THEN("The user can tell if the output is correct")
			{
				cout << "Print list forwards and backwards." << endl;
				list.display(1);
				list.display(0);
			}
		}
		WHEN("2034 is added to the beginning")
		{
			list.add_at_beg(2034);
			THEN("2034 is the first element")
			{
				REQUIRE(list.element_at(0) == 2034);
			}
		}
		WHEN("54, 32, 21, 76 are added to the beggining. And the list deletes twice.")
		{
			list.add_at_beg(54);
			list.add_at_beg(32);
			list.add_at_beg(21);
			list.add_at_beg(76);
			list.del();
			list.del();
			THEN("Count is 7")
			{
				REQUIRE(list.count() == 7);
			}
			THEN("Element at 0 is 32")
			{
				REQUIRE(list.element_at(0) == 32);
			}
			THEN("Element at 1 is 54")
			{
				REQUIRE(list.element_at(1) == 54);
			}
			THEN("Element at 6 is 1")
			{
				REQUIRE(list.element_at(6) == 1);
			}
		}
	}
}

SCENARIO("A tree can add, delete, count, and display in 3 different ways.")
{
	GIVEN("An empty tree")
	{
		Collections::tree t;
		int data[] =
		{ 32, 16, 34, 1, 87, 13, 7, 18, 14, 19, 23, 24, 41, 5, 53 };
		WHEN("15 numbers are added.")
		{
			for (int iter = 0; iter < 15; ++iter)
				t.add(data[iter]);
			THEN("Count = 15")
			{
				REQUIRE(t.count() == 15);
			}
			WHEN("Two numbers in the tree are deleted.")
			{
				t.del(16);
				t.del(41);
				THEN("Count = 13")
				{
					REQUIRE(t.count() == 13);
				}
			}
			WHEN("A number not in the tree is deleted.")
			{
				t.del(408);
				THEN("The count remains 15")
				{
					REQUIRE(t.count() == 15);
				}
			}
		}
	}
}


SCENARIO("Linked List Can Append, Delete, Insert, Access, and Count")
{
	Collections::LinkedList l;
	l.append(12);
	l.append(13);
	l.append(23);
	l.append(43);
	l.append(44);
	l.append(50);
	REQUIRE(l.count() == 6);
	l.add_as_first(2);
	l.add_as_first(1);
	REQUIRE(l.count() == 8);
	l.add_after(3, 333);
	l.add_after(6, 666);
	auto v1 = l.element_at(4);
	CAPTURE(v1);
	REQUIRE(v1 == 333);
	auto v2 = l.element_at(7);
	CAPTURE(v2);
	REQUIRE(v2 == 666);
	REQUIRE(l.count() == 10);
	l.del(333);
	l.del(12);
	l.del(98); //does not contain 98
	REQUIRE(l.count() == 8);
}

SCENARIO("LQueues can add, delete, and count. Only limited by available memory.")
{
	Collections::LQueue queue;
	GIVEN("A LQueue with [20, 88, 0, 43030]")
	{
		queue.add(20);
		queue.add(88);
		queue.add(0);
		queue.add(43030);
		REQUIRE(queue.count() == 4);
		WHEN("We delete three times.")
		{
			int d1 = queue.del();
			int d2 = queue.del();
			int d3 = queue.del();
			THEN("We get 20, 88, and 0; and count shrinks to 1.")
			{
				REQUIRE(d1 == 20);
				REQUIRE(d2 == 88);
				REQUIRE(d3 == 0);
				REQUIRE(queue.count() == 1);
			}
		}
		WHEN("We add 30 more items.")
		{
			for (int i = 0; i < 30; ++i)
				queue.add(i);
			THEN("Count = 34")
			{
				REQUIRE(queue.count() == 34);
			}
		}
		WHEN("We add 100 then remove 105.")
		{
			for (int i = 0; i < 100; ++i)
				queue.add(i);
			for (int i = 0; i < 105; ++i)
				queue.del();
			THEN("count == 0")
			{
				REQUIRE(queue.count() == 0);
			}
		}
	}
}


SCENARIO("Queues can add, del, and count")
{
	int data[5] = { 32, 23, 45, 99, 24 };
	Collections::Queue _queue;
	REQUIRE(_queue.count() == 0);

	for (int iter = 0; iter < 5; ++iter)
		_queue.add(data[iter]);
	REQUIRE(_queue.count() == 5);

	for (int iter = 0; iter < 5; ++iter)
		_queue.del();
	REQUIRE(_queue.count() == 0);
}

SCENARIO("Stacks can insert, delete, and count. They have a maximum of 10 integers.")
{
	Collections::Stack stack;
	GIVEN("A stack of 5 numbers")
	{
		stack.push(10);
		stack.push(30);
		stack.push(90);
		stack.push(120);
		stack.push(150);
		WHEN("2 more are added")
		{
			stack.push(180);
			stack.push(210);
			THEN("count() == 7")
			{
				REQUIRE(stack.count() == 7);
			}
		}
		WHEN("2 are deleted")
		{
			stack.pop();
			stack.pop();
			THEN("count() == 3")
			{
				REQUIRE(stack.count() == 3);
			}
		}
		WHEN("6 are deleted")
		{
			for (int i = 0; i < 6; ++i)
				stack.pop();
			THEN("count() == 0")
			{
				REQUIRE(stack.count() == 0);
			}
		}
		WHEN("6 are added")
		{
			for (int i = 0; i < 6; ++i)
				stack.push(i * 17);
			THEN("count() == 10")
			{
				REQUIRE(stack.count() == 10);
			}
		}
	}
}


SCENARIO("LStacks can Push, Pop, and Count. Without limit.")
{
	Collections::LStack stack;
	GIVEN("A stack with 5, 8, and 7")
	{
		stack.push(5);
		stack.push(8);
		stack.push(7);
		REQUIRE(stack.count() == 3);
		WHEN("5 things are pushed")
		{
			int n;
			for (int i = 0; i < 5; ++i)
			{
				n = i * 5;
				CAPTURE(n)
					stack.push(n);
			}
			THEN("Count = 8")
			{
				REQUIRE(stack.count() == 8);
			}
		}
		WHEN("The stack is popped")
		{
			THEN("We get 7 and count is 2")
			{
				int result;
				result = stack.pop();
				CAPTURE(result);
				REQUIRE(result == 7);
				CAPTURE(stack.count())
					REQUIRE(stack.count() == 2);
			}
		}
	}
}