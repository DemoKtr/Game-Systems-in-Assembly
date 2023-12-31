#pragma once
#include <iostream>
#include <Math.h>
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
	void add_asm(const Vector3& w1);
	void sub(Vector3 w1);
	void sub_asm(const Vector3& w1);
	void mul(Vector3 w1);
	void mul_asm(const Vector3& w1);
	void mul(float value);
	void mul_asm(const float& value);
	void div(float value);
	void div_asm(const float& value);
	void normalize();
	void normalize_asm();
	float lenght();
	float lenght_asm();
	float dotproduct(Vector3 w1);
	float dotproduct_asm(const Vector3& w1);
	Vector3 crossproduct(Vector3 w1);
	void crossproduct_asm(const Vector3& w1, const Vector3& w2);
	

	float getX();
	float getX_asm();
	float getY();
	float getY_asm();
	float getZ();
	float getZ_asm();
	void write();
};

