#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "StackTester.h"

int main(int argc, char* const argv[])
{
	//global setup
	int result = Catch::Session().run(argc, argv);
	//global cleanup
	printf("Ampersand Program Begins...\n");
	StackTester().Test();
	std::cin.get();
}