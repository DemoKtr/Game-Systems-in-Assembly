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

		movups xmm0, [ecx]; Wczytaj sk³adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk³adowe x, y, z z w1 do xmm1

		addps xmm0, xmm1; Dodaj xmm0 i xmm1

		movups[ecx], xmm0; Zapisz wynik z powrotem do sk³adowych x, y, z
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

		movups xmm0, [ecx]; Wczytaj sk³adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk³adowe x, y, z z w1 do xmm1

		subps xmm0, xmm1; Odejmij xmm1 od xmm0

		movups[ecx], xmm0; Zapisz wynik z powrotem do sk³adowych x, y, z
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

		movups xmm0, [ecx]; Wczytaj sk³adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk³adowe x, y, z z w1 do xmm1

		mulps xmm0, xmm1; 

		movups[ecx], xmm0; Zapisz wynik z powrotem do sk³adowych x, y, z
	}
}

void Vector3::mul(float value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
}

void Vector3::mul_asm(const float& value)
{
	Vector3* w1 = new Vector3(value, value, value);
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		mov edx, w1; Wczytaj wartoœæ value do xmm0

		movups xmm0, [ecx]; Wczytaj sk³adowe x, y, z do xmm0
		movups xmm1, [edx]; Wczytaj sk³adowe x, y, z z w1 do xmm1

		mulps xmm1, xmm0; Pomnó¿ xmm1 przez xmm0

		movups[ecx], xmm1; Zapisz wynik z powrotem do sk³adowych x, y, z
	}
	delete w1;
}

void Vector3::div(float value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
}

void Vector3::div_asm(const float& value)
{
	Vector3* w1 = new Vector3(value, value, value);
	__asm {
		mov ecx, this
		mov edx, w1

		movups xmm0, [ecx]
		movups xmm1, [edx]

		divps xmm0, xmm1

		movups[ecx], xmm0
	}
	delete w1;
}


void Vector3::normalize()
{
	float len = this->lenght();
	if (len != 0.0) {
		div(len);
	}
}

void Vector3::normalize_asm()
{
	float len = this->lenght_asm();
	__asm 
	{
		mov ecx,this
		mov eax,len
		cmp eax,0
		jne calculate
		jmp end

		calculate:
		movups xmm0,[ecx]
		movups xmm1,len
		shufps xmm1,xmm1,0
		divps xmm0,xmm1
		jmp end

		end:
		movups[ecx], xmm0

	}
}



float Vector3::lenght()
{
	return sqrt(this->x*this->x+ this->y * this->y + this->z * this->z);
}

float Vector3::lenght_asm()
{
	float result;
	__asm {
		mov ecx, this
		

		movups xmm0, [ecx]
		mulps xmm0,xmm0
		movups xmm1, [ecx + 4]
		mulps xmm1, xmm1
		movups xmm2, [ecx + 8]
		mulps xmm2, xmm2
		addps xmm0, xmm1
		addps xmm0, xmm2
		sqrtss xmm0,xmm0

		
		
		movss result,xmm0
		
	}
	return result;
}

float Vector3::dotproduct(Vector3 w1)
{
	return this->x*w1.getX() + this->y*w1.getY() +this->z*w1.getZ();
}

float Vector3::dotproduct_asm(const Vector3& w1)
{
	float result;
	__asm
	{
		mov ecx, this
		mov edx, w1
		movups xmm0, [ecx]
		movups xmm1, [edx]
		mulps xmm0, xmm1

		movups xmm1, [ecx + 4]
		movups xmm2, [edx + 4]
		mulps xmm1, xmm2
		addps xmm0, xmm1

		movups xmm1, [ecx + 8]
		movups xmm2, [edx + 8]
		mulps xmm1, xmm2
		addps xmm0, xmm1

		movss result, xmm0
	}
	return result;
}

Vector3 Vector3::crossproduct(Vector3 w1)
{
	return Vector3();
}

float Vector3::getX()
{
	return this->x;
	
}
float Vector3::getX_asm()
{
	float result;
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		movups xmm0, [ecx]
		movss result,xmm0
	}
	return result;
}
float Vector3::getY()
{
	return this->y;
}
float Vector3::getY_asm()
{
	float result;
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		movups xmm0, [ecx + 4]
		movss result, xmm0
	}
	return result;
}
float Vector3::getZ()
{
	return this->z;
}
float Vector3::getZ_asm()
{
	float result;
	__asm {
		mov ecx, this; Adres obiektu Vector3(this)
		movups xmm0, [ecx + 8]
		movss result, xmm0
	}
	return result;
}
void Vector3::write()
{
	std::cout << "X: " << this->x << " Y:" << this->y << " Z: " << this->z << std::endl;
}
