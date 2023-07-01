#pragma once
#include <math.h>
class Vector2
{
	float x, y;
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& other);
	~Vector2();
	float Distance_asm(Vector2* v1);
	float Distance(Vector2* v1);
	//getter setter
	float getX();
	float getY();
	void setX(float a);
	void setY(float a);
	
};

