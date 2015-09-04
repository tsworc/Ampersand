#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DL_List.h"
#include <iostream>
#include "GenericRingBuffer.h"
using namespace Collections;

int main(int argc, char* const argv[])
{
	//global setup
	int result = Catch::Session().run(argc, argv);
	//global cleanup
	printf("Ampersand Program Begins...\n");
	std::cin.get();
}

SCENARIO("Generic ring buffers can enqueue, dequeue, and count. With no size limitations besides memory.")
{
	GIVEN("A ring buffer with strings [run, jump, duck, dive, dodge, dip, dive]")
	{
		GenericRingBuffer<char*> buffer;
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