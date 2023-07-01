#include <iostream>
#include <chrono>

#include "Timer.h"
#include "Vector2.h"
#include "MathEngine.h"

int main() {

	//start timer
	Vector2* v1 = new Vector2(-3, -2);
	Vector2* v2 = new Vector2(2,-2);
	Vector2* v3 = new Vector2(2,2);
	int b=-2;
	MathEngine mk;
	b = mk.rectangular(v1, v2, v3);
	std::cout << b << std::endl;
	

	return 0;
}