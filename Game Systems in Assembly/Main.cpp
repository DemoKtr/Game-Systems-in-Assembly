#include <iostream>
#include <chrono>

int main() {

	//start timer
	std::chrono::high_resolution_clock::time_point start1 = std::chrono::high_resolution_clock::now();
	int result1 = 0;

	__asm
	{
		mov eax,2
		mov ebx,3
		add eax,ebx
		mov result1,eax
	}

	std::chrono::high_resolution_clock::time_point end1 = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
	std::cout << "Time: " << duration.count() / 1000000.0 << " ms" << std::endl;
	std::cout << result1 << std::endl;
	//////////////////////////
	std::chrono::high_resolution_clock::time_point start2 = std::chrono::high_resolution_clock::now();
	int result2 = 0;
	result2 = 2 + 3;
	std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
	std::cout << "Time: " << duration.count() / 1000000.0 << " ms" << std::endl;
	std::cout << result2 << std::endl;
	return 0;
}