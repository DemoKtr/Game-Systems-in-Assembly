#include <iostream>
#include <chrono>

#include "Timer.h"
#include "Vector2.h"
#include "MathEngine.h"


int main() {

	//start timer
	Timer* t1 = new Timer();
	t1->start_timer();
	Vector2* v1 = new Vector2(-3, -2);
	Vector2* v2 = new Vector2(2,2);
	Vector2* v3 = new Vector2(2,-2);
	MathEngine mk; 
	std::cout << mk.rectangular(v1, v2, v3)<< std::endl;
	t1->stop_timer();
	t1->display_timer();
	delete v1;
	delete v2;
	delete v3;
	delete t1;


	Timer* t2 = new Timer();
	t2->start_timer();
	Vector2* v4 = new Vector2(-3, -2);
	Vector2* v5 = new Vector2(2, 2);
	Vector2* v6 = new Vector2(2, -2);

	float v1v2 = v5->Distance(v6);
	float v1v3 = v4->Distance(v6);
	float v2v3 =  v4->Distance(v5);

	v1v2 *= v1v2;
	v1v3 *= v1v3;
	v2v3 *= v2v3;

	
	t2->stop_timer();
	t2->display_timer();
	return 0;
}