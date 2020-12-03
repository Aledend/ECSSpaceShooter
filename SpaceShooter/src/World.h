#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "ComponentArray.h"
#include "Components.h"
#include "Systems.h"
#include <vector>
#include <memory>
#include <queue>
#include <map>

struct SDL_Renderer;
struct SDL_Window;

class World {
public:
	World(SDL_Renderer* renderer, SDL_Window* window, const Uint8* keyboard);
	~World();

	void Update();
	std::array<Entity, MAX_ENTITIES>& GetEntities();

	template<class ComponentType>
	ComponentType* GetComponents();

	template<class ComponentType>
	ComponentType* GetComponent(ecs_numeric EntityID);

	template<class ...Components>
	ecs_numeric CreateEntity();

	void DestroyEntity(ecs_numeric entityID);

	
private:
	void SetupSystems();

private:
	std::vector<ecs_numeric> availableEntityIDs;
	std::array<Entity, MAX_ENTITIES> entities;
	ComponentArrays componentArrays;
	std::vector<System*> systems;

public:
	SDL_Renderer* renderer;
	SDL_Window* window;
	const Uint8* keyboard;
};

template<class ComponentType>
inline ComponentType* World::GetComponents()
{
	return componentArrays.GetComponentArray<ComponentType>();
}

template<class ComponentType>
inline ComponentType* World::GetComponent(ecs_numeric EntityID)
{
	return &GetComponents<ComponentType>()[EntityID];
}

template<class ...Components>
inline ecs_numeric World::CreateEntity()
{
	ecs_numeric entityID = availableEntityIDs.back();
	availableEntityIDs.pop_back();

	entities[entityID].AddComponents<Components...>();

	return entityID;
}
