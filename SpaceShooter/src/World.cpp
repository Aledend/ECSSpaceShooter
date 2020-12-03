#include "World.h"
#include <iostream>
#include "ComponentHelper.h"
#include "Engine/Time.h"
#include "EntityHelper.h"
#include "SDL.h"


World::World(SDL_Renderer* rend, SDL_Window* win, const Uint8* keyboard)
{
	renderer = rend;
	window = win;
	this->keyboard = keyboard;

	availableEntityIDs.reserve(MAX_ENTITIES);
	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++)
	{
		availableEntityIDs.push_back(i);
	}


	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++) {
		EntityHelper::CreatePlayer(this);
	}

	SetupSystems();
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

std::array<Entity, MAX_ENTITIES>& World::GetEntities()
{
	return entities;
}


void World::DestroyEntity(ecs_numeric entityID)
{
	entities[entityID].RemoveComponents();
	availableEntityIDs.push_back(entityID);
}


void World::SetupSystems()
{
	//systems.push_back(new UpdateInput());
	systems.push_back(new ControlPlayers());
	systems.push_back(new MovePlayers());

	// Setup last.
	systems.push_back(new Render());
}

