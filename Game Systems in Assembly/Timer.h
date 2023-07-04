#pragma once
#ifndef Timer_H
#define Timer_H

#include <chrono>
#include <string>
#include <iostream>


class Timer
{
private:
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point stop;
public:
	Timer() {
		this->start = std::chrono::high_resolution_clock::now();
		this->stop = std::chrono::high_resolution_clock::now();
	}
	~Timer() {

	}
      void start_timer() {
		  this->start = std::chrono::high_resolution_clock::now();
}
	  void stop_timer() {
		  stop = std::chrono::high_resolution_clock::now();
	  }
	  void display_timer() {
		  std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		  std::cout << "Time: " << duration.count() / 1000000.0 << " ms" << std::endl;
	  }
};

#endif 