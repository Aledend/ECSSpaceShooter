#include "Application.h"
#include "SDL.h"
#include <iostream>

namespace Engine {
	Application::Application()
	{

	}

	Application::~Application() {

	}

	bool Application::InitSDL(const char* title, int width, int height, bool fullscreen)
	{
		Uint32 flags = SDL_WINDOW_SHOWN;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			if (!(window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN)))
			{
				std::cout << "Error. Window could not be created" << std::endl;
				return false;
			}

			if (!(renderer = SDL_CreateRenderer(window, -1, 0)))
			{
				std::cout << "Error. Renderer could not be created." << std::endl;
				return false;
			}
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

			isRunning = true;
			return true;
		}
		else
		{
			isRunning = false;
			std::cout << "Error. SDL couldn't be initialized." << std::endl;
			return false;
		}
	}

	void Application::HandleEvents()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}

	void Application::InitApplication()
	{
	}

	void Application::Update()
	{
		applicationTime.Update();

		
	}

	void Application::Render()
	{
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	void Application::Clean()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}

	void Application::Run()
	{
		if (!InitSDL("SpaceShooter", 800, 600, false)) {
			return;
		}
		SDL_Delay(300);

		InitApplication();

		while (isRunning) {
			HandleEvents();
			Update();
			Render();
		}

		Clean();
	}

	bool Application::IsRunning()
	{
		return isRunning;
	}
}