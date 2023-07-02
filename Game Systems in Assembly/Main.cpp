#include <iostream>
#include <chrono>

#include "Timer.h"
#include "Vector2.h"
#include "Vector3.h"
#include "MathEngine.h"


int main() {

	Vector3 w1(2, 3, 4);
	Vector3 w2(1, 1, 2);
	w1.add(w2);
	w1.write();
	
	return 0;
}