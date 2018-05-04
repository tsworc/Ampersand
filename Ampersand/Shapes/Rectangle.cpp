#include "Rectangle.h"

Rectangle::Rectangle() {
	x = y = width = height = 0;
}
Rectangle::Rectangle(Rectangle& cpy) {
	x = cpy.x;
	y = cpy.y;
	width = cpy.width;
	height = cpy.height;
}
Rectangle::Rectangle(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
Rectangle::~Rectangle()
{

}

bool Rectangle::Intersects(Rectangle r)
{
	if (x > r.GetRight())
	{
		return false;
	}
	if (GetRight() < r.x)
	{
		return false;
	}
	if (y > r.GetBottom())
	{
		return false;
	}
	if (GetBottom() < r.y)
	{
		return false;
	}
	return true;
}