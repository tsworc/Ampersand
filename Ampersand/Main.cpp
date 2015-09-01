#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DL_List.h"
#include <iostream>

int main(int argc, char* const argv[])
{
	//global setup
	int result = Catch::Session().run(argc, argv);
	//global cleanup
	printf("Ampersand Program Begins...\n");
	std::cin.get();
}