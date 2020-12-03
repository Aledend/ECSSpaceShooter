#include "Time.h"
#include <thread>
#include <chrono>
#include <iostream>


namespace Engine {
	Time::Time()
	{
		time = 0.f;
		deltaTime = 0.f;
		currentTime = std::chrono::high_resolution_clock::now();
	}

	void Time::Update()
	{
		deltaCount = std::chrono::high_resolution_clock::now() - currentTime;
		deltaTime = deltaCount.count();
		std::cout << "fps: " << 1 / deltaTime << std::endl;
		currentTime = std::chrono::high_resolution_clock::now();
	}
}
