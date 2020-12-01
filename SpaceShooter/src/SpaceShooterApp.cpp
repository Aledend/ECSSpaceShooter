#include <Engine.h>
#include "Entity.h"
#include "Components.h"
#include "World.h"
#include <iostream>
#include <Math.h>
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

		std::cout << "vel: " << ComponentHelper::GetComponentID<Velocity>() << std::endl;
		std::cout << "pos: " << ComponentHelper::GetComponentID<Position>() << std::endl;

		Entity player = Entity();
		player.AddComponents<Position, Player, Velocity>();

		std::cout << "creating world" << std::endl;
		world = new World();


		
	}

	void Update() override {
		Engine::Application::Update();
		std::cout << "updating" << std::endl;
		world->Update();
	}

private:
	/*Entity<>* player;*/
};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}