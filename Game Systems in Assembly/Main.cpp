#include <iostream>
#include <chrono>

#include "Timer.h"
#include "Vector2.h"
#include "Vector3.h"
#include "MathEngine.h"


int main() {
	

	Vector3 w1(0, 3, 4);
	Vector3 w2(4, 6, 1);
	Vector3 *w= new Vector3(1,1,1);

	w->crossproduct_asm(w1, w2);
	w1.add_asm(*w);
	std::cout << "X: " << w1.getX() << " Y:" << w1.getY() << " Z: " << w1.getZ() << std::endl;
	w = nullptr;
	delete w;
	return 0;
}