#include "World.h"
#include <iostream>
#include "ComponentHelper.h"
#include "Engine/Time.h"
#include "EntityHelper.h"


World::World()
{
	availableEntityIDs.reserve(MAX_ENTITIES);
	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++)
	{
		availableEntityIDs.push_back(i);
	}

	systems.push_back(new MoveBullets());

	ecs_numeric bullet1 = EntityHelper::ReserveBullet(this);
	ecs_numeric bullet2 = EntityHelper::ReserveBullet(this);

	//systems.emplace_back(std::make_unique<MoveBullets>());


	//entities[0].AddComponent<Sprite>();
	//entities[0].AddComponent<Velocity>();
	//entities[0].AddComponents<Bullet, Position, Velocity, Sprite, CircleCollider>();
	
	Velocity* vel = GetComponent<Velocity>(bullet1);// static_cast<Velocity*>(&componentArray[ComponentHelper::GetComponentID<Velocity>()].components[0]);
	vel->xVel = 1.f;
	vel->yVel = 1.f;



	Velocity* vel2 = GetComponent<Velocity>(bullet2);
	vel2->xVel = 2.f;
	vel2->yVel = 2.f;

	//std::cout << vel->yVel << std::endl;
	//std::cout << vel->xVel << std::endl;
	//std::cout << vel2->yVel << std::endl;
	//std::cout << vel2->xVel << std::endl;

	//std::cout << "mask: " << GetEntities()[0].HasComponents<Bullet, Velocity>() << std::endl;
}

World::~World()
{
    for (System* s : systems)
	{
		delete s;
	}
}

void World::Update()
{
	
	for (System* s : systems)
	{
		
		s->HandleLogic(this);
	}

	/*Position* pos = GetComponent<Position>(MAX_ENTITIES - 1);
	std::cout << "x: " << pos->x << ", y: " << pos->y << std::endl;*/
}

std::array<Entity, MAX_ENTITIES>& World::GetEntities()
{
	return entities;
}

void World::DestroyEntity(ecs_numeric entityID)
{
	entities[entityID].RemoveComponents();
	availableEntityIDs.push_back(entityID);
}

