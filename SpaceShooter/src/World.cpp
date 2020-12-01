#include "World.h"
#include <iostream>
#include "ComponentHelper.h"
#include "Components.h"
#include "Engine/Time.h"


World::World()
{
	std::cout << "pos: " << ComponentHelper::GetComponentID<Position>() << std::endl;
	std::cout << "vel: " << ComponentHelper::GetComponentID<Velocity>() << std::endl;
	

}

World::~World()
{
	
}

void World::Update()
{
	std::cout << "time: " << Engine::Time::deltaTime << std::endl;
	for (System s : systems)
	{
		
		//s.HandleLogic();
	}
}
