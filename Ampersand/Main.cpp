#include <iostream>
#include "StackTester.h"
#include "QueueTester.h"

int main(int argc, char*argv)
{
	printf("Ampersand Program Begins...\n");
	StackTester().Test();
	QueueTester().Test();
	std::cin.get();
}