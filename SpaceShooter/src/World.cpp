#include "World.h"
#include <iostream>
#include "ComponentHelper.h"
#include "Engine/Time.h"


World::World()
{

	systems.emplace_back(std::make_unique<MoveBullets>());

	entities[0].AddComponents<Bullet, Position, Velocity>();
	//entities[0].AddComponent<Sprite>();
	//entities[0].AddComponent<Velocity>();
	//entities[0].AddComponents<Bullet, Position, Velocity, Sprite, CircleCollider>();
	Velocity* vel = static_cast<Velocity*>(&componentArray[ComponentHelper::GetComponentID<Velocity>()].components[0]);
	vel->xVel = 1.f;
	vel->yVel = 1.f;

	//std::cout << "mask: " << GetEntities()[0].HasComponents<Bullet, Velocity>() << std::endl;
}

World::~World()
{
	/*for (const auto& s : systems)
	{
		
	}*/
}

void World::Update()
{
	
	for (const auto& s : systems)
	{
		s->HandleLogic(this);
	}

	//Position* pos = static_cast<Position*>(&componentArray[ComponentHelper::GetComponentID<Position>()].components[0]);
	

}

Entity* World::GetEntities()
{
	return entities;
}

//template<class ComponentType>
//ComponentArray* World::GetComponents()
//{
//	return componentArray;//&componentArray[ComponentHelper::GetComponentID<ComponentType>()].components;
//}
