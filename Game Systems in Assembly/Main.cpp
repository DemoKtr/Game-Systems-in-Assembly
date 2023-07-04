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
	Timer* t = new Timer();
	std::cout << "Jebane C++" << std::endl;
	t->start_timer();
	 w1->getZ();
	t->stop_timer();
	t->display_timer();
	std::cout << "LoveAssembler<3: " << std::endl;
	t->start_timer();
	w1->getZ_asm();
	t->stop_timer();
	t->display_timer();
	return 0;
}