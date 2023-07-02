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
