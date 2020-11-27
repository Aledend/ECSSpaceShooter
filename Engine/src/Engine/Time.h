#pragma once
#include <chrono>
class Time
{
public:
	Time();
	/// <summary>
	/// Time since application was launched.
	/// </summary>
	inline static float time;
	/// <summary>
	/// The amount of time the last frame took.
	/// </summary>
	inline static float deltaTime;
	
	void Update();

private:
	class std::chrono::system_clock::time_point currentTime;

};

