#include <iostream>
#include <chrono>

#include "Timer.h"
#include "Vector2.h"
#include "Vector3.h"
#include "MathEngine.h"


int main() {
	/*
	Vector3* w1= new Vector3(2, 3, 4);
	Vector3 w2(1, 1, 2);
	w1->add_asm(w2);
	w1->write();
	*/
	Vector3* w1 = new Vector3(2, 3, 4);
	std::cout << "C++ (ten gorszy):" << std::endl;
	Vector3 w2(1, 1, 2);
	w1->mul(w2);
	w1->write();
	w1=new Vector3(2, 3, 4);
	std::cout << "Assembler:" << std::endl;
	w1->mul_asm(w2);
	w1->write();
	return 0;
}