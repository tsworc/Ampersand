#include "Catch.hpp"
#include "MathFuncsLib.h"

using namespace MathFuncs;

SCENARIO("MathFuncsLib can add, divide, subtract, and multiply floating point numbers.")
{
	GIVEN("Two numbers 5 and 7.77")
	{
		double a = 5;
		double b = 7.77;
		WHEN("added together")
		{
			THEN("the result is 12.77")
			{
				REQUIRE(MyMathFuncs::Add(a, b) == Approx(12.77));
			}
		}
		WHEN("subtracting b from a")
		{
			THEN("the result is -2.77")
			{
				REQUIRE(MyMathFuncs::Subtract(a, b) == Approx(-2.77));
			}
		}
		WHEN("Multiplied")
		{
			THEN("The result is 38.85")
			{
				REQUIRE(MyMathFuncs::Multipy(a, b) == Approx(38.85));
			}
		}
		WHEN("Dividing b from a")
		{
			THEN("The result is ~0.6435")
			{
				REQUIRE(MyMathFuncs::Divide(a, b) == Approx(0.6435));
			}
		}
	}
}