#pragma once

#include "Core.h"
#include "Time.h"
#include <cstdint>
#include <SDL.h>

struct SDL_Window;
struct SDL_Renderer;

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		bool InitSDL(const char* title, int width, int height, bool fullscreen);

		void HandleEvents();
		virtual void InitApplication();
		virtual void Update();
		/*virtual void RenderApplication();
		void RenderBegin();
		void RenderPresent();*/
		//void Render();
		void Clean();
		bool IsRunning();

		void Run();

	private:
		bool isRunning;
		Time applicationTime;

	protected:
		SDL_Window* window;
		SDL_Renderer* renderer;
		const Uint8* keyboard;
	};

	// To be defined in client
	Application* CreateApplication();
}

