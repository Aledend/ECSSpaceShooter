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

	}

	void InitApplication() override {

		std::cout << "vel: " << ComponentHelper::GetComponentID<Velocity>() << std::endl;
		std::cout << "pos: " << ComponentHelper::GetComponentID<Position>() << std::endl;

		Entity player = Entity();
		player.AddComponents<Position, Player, Velocity>();

		World* world = new World();


		delete world;
	}

	void Update() override {
		Engine::Application::Update();
	}

private:
	/*Entity<>* player;*/
};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}