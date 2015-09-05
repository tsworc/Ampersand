#define CATCH_CONFIG_RUNNER
#include "Catch.hpp"
#include <iostream>

int main(int argc, char* const argv[])
{
	//global setup
	int result = Catch::Session().run(argc, argv);
	//global cleanup
	printf("Ampersand Program Begins...\n");
	std::cin.get();
}