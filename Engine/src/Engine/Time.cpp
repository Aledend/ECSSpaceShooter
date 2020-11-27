#include "Time.h"
#include "Time.h"

Time::Time()
{
	time = 0.f;
	deltaTime = 0.f;
	currentTime = std::chrono::system_clock::now();
}

void Time::Update()
{
	deltaTime = (std::chrono::system_clock::now() - currentTime).count();
	currentTime = std::chrono::system_clock::now();
}
