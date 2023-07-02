#include "Vector3.h"

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{

}

void Vector3::add(Vector3 w1)
{
	this->x = x + w1.getX();
	this->y = y + w1.getY();
	this->z = z + w1.getZ();
	
}

void Vector3::add_asm(Vector3 w1)
{
	float* kk = &this->x;
	__asm {
		movaps  xmm0, [kk]        // xmm0 = wartoœæ x dla this
		addss xmm0, [w1]          // xmm0 += wartoœæ x dla w1
		movss[this], xmm0        // zapisz wynik xmm0 do this->x

		movss xmm1, [this + 4]    // xmm1 = wartoœæ y dla this
		addss xmm1, [w1 + 4]      // xmm1 += wartoœæ y dla w1
		movss[this + 4], xmm1    // zapisz wynik xmm1 do this->y

		movss xmm2, [this + 8]    // xmm2 = wartoœæ z dla this
		addss xmm2, [w1 + 8]      // xmm2 += wartoœæ z dla w1
		movss[this + 8], xmm2    // zapisz wynik xmm2 do this->z
	}
}

void Vector3::sub(Vector3 w1)
{
	this->x -= w1.getX();
	this->y -= w1.getY();
	this->z -= w1.getZ();
}

void Vector3::mul(Vector3 w1)
{
	this->x *= w1.getX();
	this->y *= w1.getY();
	this->z *= w1.getZ();
}

void Vector3::mul(float value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
}

void Vector3::div(float value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
}

void Vector3::normalize()
{
	float len = this->lenght();
	if (len != 0.0) {
		div(len);
	}
}



float Vector3::lenght()
{
	return sqrt(this->x*this->x+ this->y * this->y + this->z * this->z);
}

float Vector3::dotproduct(Vector3 w1)
{
	return this->x*w1.getX() + this->y*w1.getY() +this->z*w1.getZ();
}

Vector3 Vector3::crossproduct(Vector3 w1)
{
	return Vector3();
}

float Vector3::getX()
{
	return this->x;
}
float Vector3::getY()
{
	return this->y;
}
float Vector3::getZ()
{
	return this->z;
}
void Vector3::write()
{
	std::cout << "X: " << this->x << " Y:" << this->y << " Z: " << this->z << std::endl;
}
