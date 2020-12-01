#pragma once
#include <chrono>
#include "Core.h"

namespace Engine {
	class ENGINE_API Time
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
		std::chrono::high_resolution_clock::time_point currentTime;
		std::chrono::duration<float> deltaCount;

	};

}