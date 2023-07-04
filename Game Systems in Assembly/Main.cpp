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

	Vector3 w1(0, 3, 4);
	Vector3 w2(4, 6, 1);
	//Timer t;
	Vector3* w=new Vector3(3,3,3);
//	t.start_timer();
	w->crossproduct_asm(w1,w2);
	w->write();
	//t.stop_timer();
	//t.display_timer();
	
	std::cout << "123";
	return 0;
}