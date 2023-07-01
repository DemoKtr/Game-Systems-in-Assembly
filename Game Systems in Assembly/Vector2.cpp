#include "Vector2.h"


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
Vector2::Vector2(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
}
Vector2::~Vector2() {

}

float Vector2::Distance_asm(Vector2* v1)
{
	float a2 = v1->getX();
	float b2 = v1->getY();
	float a1 = this->x;
	float b1 = this->y;
	float distance = 0;
	__asm
	{
		fld a1      // Za�adowanie a1 na stos FPU
		fld a2      // Za�adowanie a2 na stos FPU
		fsub       // Odj�cie a2 od a1
		fmul st(0), st(0)  // Kwadrat r�nicy a1-a2
		fld b1      // Za�adowanie b1 na stos FPU
		fld b2      // Za�adowanie b2 na stos FPU
		fsub       // Odj�cie b2 od b1
		fmul st(0), st(0)  // Kwadrat r�nicy b1-b2
		fadd       // Dodanie kwadrat�w r�nic
		fsqrt      // Pierwiastek kwadratowy z sumy
		fstp distance     // Wynik na distance

	}
	return distance;
}

float Vector2::Distance(Vector2* v1)
{
	float result = (float)sqrt((this->x+v1->getX())*(this->x + v1->getX())+ (this->y + v1->getY()) * (this->y + v1->getY()));
	return 0.0f;
}

float Vector2::getX()
{
	return this->x;
}

float Vector2::getY()
{
	return this->y;
}

void Vector2::setX(float a)
{
	this->x = a;
}

void Vector2::setY(float a)
{
	this->y = a;
}
