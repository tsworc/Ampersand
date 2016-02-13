#pragma once

class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3();
	Vector3(Vector3&);
	Vector3(float, float, float);
	~Vector3();

	static float DotProduct(Vector3, Vector3);
};