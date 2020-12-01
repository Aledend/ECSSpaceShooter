#include "Time.h"
#include <thread>
#include <chrono>

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
		currentTime = std::chrono::high_resolution_clock::now();
		
		using namespace std::chrono_literals;

		std::this_thread::sleep_for(200ms);
	}
}
