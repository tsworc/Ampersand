#include "Catch.hpp"
#include "Header\Collections\Generic\GenericStack.h"
#include "Header\Collections\Generic\GenericRingBuffer.h"

SCENARIO("Generic Stacks can store any data type. They can push, pop, and count.")
{
	cout << "TEST GENERIC_STACK" << endl;
	GIVEN("A generic stack of strings [\"Run\", \"Jump\", \"Dash Forward\", \"Dash Back\"]")
	{
		Collections::GenericStack<char *> stack;
		stack.push("Run");
		stack.push("Jump");
		stack.push("Dash Forward");
		stack.push("Dash Back");
		REQUIRE(stack.count() == 4);
		WHEN("We pop twice")
		{
			char * a = stack.pop();
			char * b = stack.pop();
			THEN("we get \"Dash Back\", \"Dash Forward\" and count is 2")
			{
				CAPTURE(a);
				CAPTURE(b);
				REQUIRE(strcmp(a, "Dash Back") == 0);
				REQUIRE(strcmp(b, "Dash Forward") == 0);
				REQUIRE(stack.count() == 2);
				cout << a << endl;
				cout << b << endl;
			}
		}
		WHEN("We pop 5 times")
		{
			for (int i = 0; i < 5; ++i)
				stack.pop();
			THEN("Count is 0")
			{
				REQUIRE(stack.count() == 0);
			}
		}
	}
}

SCENARIO("Generic ring buffers can enqueue, dequeue, and count. With no size limitations besides memory.")
{
	GIVEN("A ring buffer with strings [run, jump, duck, dive, dodge, dip, dive]")
	{
		Collections::GenericRingBuffer<char*> buffer;
		buffer.enqueue("run");
		buffer.enqueue("jump");
		buffer.enqueue("duck");
		buffer.enqueue("dive");
		buffer.enqueue("dodge");
		buffer.enqueue("dip");
		buffer.enqueue("dive");
		REQUIRE(buffer.count() == 7);
		WHEN("We enqueue another \"dodge\"")
		{
			buffer.enqueue("dodge");
			THEN("Count is 8")
			{
				REQUIRE(buffer.count() == 8);
			}
		}
		WHEN("we dequeue 3 times.")
		{
			char * a = buffer.dequeue();
			char * b = buffer.dequeue();
			char * c = buffer.dequeue();
			CAPTURE(a);
			CAPTURE(b);
			CAPTURE(c);
			THEN("we get run, jump, duck")
			{
				REQUIRE(strcmp(a, "run") == 0);
				REQUIRE(strcmp(b, "jump") == 0);
				REQUIRE(strcmp(c, "duck") == 0);
			}
		}
	}
}