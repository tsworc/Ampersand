#pragma once

class Rectangle
{
public:
	float x;
	float y;
	float width;
	float height;
	Rectangle();
	Rectangle(Rectangle&);
	Rectangle(float, float, float, float);
	~Rectangle();

	bool Intersects(Rectangle);
	float GetRight() {
		return x + width;
	}
	float GetBottom() {
		return y + height;
	}
};