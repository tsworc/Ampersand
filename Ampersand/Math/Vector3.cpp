#include "Vector3.h"

Vector3::Vector3(){
	x = y = z = 0;
}
Vector3::Vector3(Vector3& cpy){
	x = cpy.x;
	y = cpy.y;
	z = cpy.z;
}
Vector3::Vector3(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3::~Vector3()
{

}

float Vector3::DotProduct(Vector3 a, Vector3 b)
{
	return a.x * b.x + a.y * b.y;
}