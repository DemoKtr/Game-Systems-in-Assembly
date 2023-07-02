#include "Vector3.h"
#include "Timer.h"

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

void Vector3::add_asm(const Vector3& w1)
{
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		mov edx, w1; Adres obiektu Vector3 w1

		movups xmm0, [ecx]; Wczytaj sk�adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk�adowe x, y, z z w1 do xmm1

		addps xmm0, xmm1; Dodaj xmm0 i xmm1

		movups[ecx], xmm0; Zapisz wynik z powrotem do sk�adowych x, y, z
	}
}

void Vector3::sub(Vector3 w1)
{
	this->x -= w1.getX();
	this->y -= w1.getY();
	this->z -= w1.getZ();
}

void Vector3::sub_asm(const Vector3& w1)
{
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		mov edx, w1; Adres obiektu Vector3 w1

		movups xmm0, [ecx]; Wczytaj sk�adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk�adowe x, y, z z w1 do xmm1

		subps xmm0, xmm1; Odejmij xmm1 od xmm0

		movups[ecx], xmm0; Zapisz wynik z powrotem do sk�adowych x, y, z
	}
}

void Vector3::mul(Vector3 w1)
{
	this->x *= w1.getX();
	this->y *= w1.getY();
	this->z *= w1.getZ();
}

void Vector3::mul_asm(const Vector3& w1)
{
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		mov edx, w1; Adres obiektu Vector3 w1

		movups xmm0, [ecx]; Wczytaj sk�adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk�adowe x, y, z z w1 do xmm1

		mulps xmm0, xmm1; Dodaj xmm0 i xmm1

		movups[ecx], xmm0; Zapisz wynik z powrotem do sk�adowych x, y, z
	}
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