#include <iostream>
#include <chrono>

#include "Timer.h"

int main() {

	//start timer
	
	Timer* t1 = new Timer();
	Timer* t2 = new Timer();

	t1->start_timer();
	int result1 = 0;

	__asm
	{
		mov eax,2
		mov ebx,3
		add eax,ebx
		mov result1,eax
	}
	t1->stop_timer();
	t1->display_timer();
	std::cout << result1 << std::endl;
	//////////////////////////
	t2->start_timer();
	int result2 = 0;
	result2 = 2 + 3;
	t2->stop_timer();
	t2->display_timer();
	
	std::cout << result2 << std::endl;
	delete t1;
	delete t2;
	return result1;
}