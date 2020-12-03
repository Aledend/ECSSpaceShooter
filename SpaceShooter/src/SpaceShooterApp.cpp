#include <Engine.h>
#include "Entity.h"
#include "Components.h"
#include "World.h"
#include <iostream>
#include <Math.h>
#include "SDL.h"
#include "ComponentHelper.h"

class SpaceShooter : public Engine::Application
{
public:
	
	SpaceShooter()
	{

	}

	~SpaceShooter()
	{
		delete world;
	}

	World* world;

	void InitApplication() override {
		Engine::Application::InitApplication();

		world = new World(renderer, window, keyboard);
		
	}

	void Update() override {
		Engine::Application::Update();

		world->Update();
	}

private:
};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}