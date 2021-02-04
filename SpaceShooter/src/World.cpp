#include "World.h"
#include <iostream>
#include "ComponentHelper.h"
#include "Engine/Time.h"
#include "EntityHelper.h"
#include "SDL.h"
#include <numeric>






World::World(SDL_Renderer* renderer, SDL_Window* window, const Uint8* keyboard)
{
	this->renderer = renderer;
	this->window = window;
	this->keyboard = keyboard;

	// Fill available entities with range [0...MAX_ENTITIES)
	availableEntityIDs.reserve(MAX_ENTITIES);
	std::iota(availableEntityIDs.begin(), availableEntityIDs.end(), 0);

	SetupSystems();

	ecs_numeric entity = CreateEntity<Player, Position, Velocity, Sprite>();
	GetComponent<Position>(entity)->Set(500.f, 500.f);
	GetComponent<Velocity>(entity)->Set(10.f, 2.f);
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
}

void World::SetupSystems()
{
	//systems.push_back(new UpdateInput());
	systems.push_back(new ControlPlayers());
	systems.push_back(new MovePlayers());

	// Setup last.
	systems.push_back(new Render());
}


std::array<Entity, MAX_ENTITIES>& World::GetEntities()
{
	return entities;
}

Entity& World::GetEntity(ecs_numeric entityID)
{
	return GetEntities()[entityID];
}

void World::DestroyEntity(ecs_numeric entityID)
{
	entities[entityID].RemoveComponents();
	availableEntityIDs.push_back(entityID);
}


