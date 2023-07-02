#pragma once
#include <iostream>
class Vector3
{
private:
	float x;
	float y;
	float z;
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	void add(Vector3 w1);
	void sub(Vector3 w1);
	void mul(Vector3 w1);
	void mul(float value);
	void div(float value);
	void normalize(float value);
	float lenght(float value);
	float dotproduct(float value);
	void crossproduct(float value);
	

	float getX();
	float getY();
	float getZ();
	void write();
};

