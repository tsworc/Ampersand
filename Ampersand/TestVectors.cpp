#include "Catch.hpp"
#include "Vector3.h"

SCENARIO("Vectors can be coordinates or directions. Operations can be performed on vectors like Dot product, cross product, normalization, etc.")
{
	GIVEN("One vector")
	{
		Vector3 vector_a;
		WHEN("We use the default constructor")
		{
			vector_a = Vector3();
			THEN("The vector is at (0,0,0)")
			{
				REQUIRE(vector_a.x == 0);
				REQUIRE(vector_a.y == 0);
				REQUIRE(vector_a.z == 0);
			}
		}
		WHEN("We construct a vector at coordinate (3, 0.1, 100)")
		{
			vector_a = Vector3(3, 0.1f, 100);
			THEN("The vector is at (3, 0.1, 100)")
			{
				REQUIRE(vector_a.x == Approx(3));
				REQUIRE(vector_a.y == Approx(0.1f));
				REQUIRE(vector_a.z == Approx(100));
			}
		}
		WHEN("We construct a copy of vector(52, 4.89, 70)")
		{
			Vector3 cpy = Vector3(52, 4.89f, 70);
			vector_a = Vector3(cpy);
			THEN("We get a perfect copy")
			{
				REQUIRE(vector_a.x == Approx(52));
				REQUIRE(vector_a.y == Approx(4.89f));
				REQUIRE(vector_a.z == Approx(70));
			}
		}
	}
	GIVEN("Two Vectors")
	{
		Vector3 vector_a;
		Vector3 vector_b;
		WHEN("A = (0,1,0) and B = (1,0,0)")
		{

		}
		WHEN("A = (1,0,0) and B = (5,0,0)")
		{

		}
	}
}