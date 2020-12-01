#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "ComponentArray.h"
#include "Components.h"
#include "Systems.h"
#include <vector>
#include <memory>

class World {
public:
	World();
	~World();

	void Update();
	Entity* GetEntities();

	template<class ComponentType>
	Component* GetComponents();

private:
	Entity entities[MAX_ENTITIES];
	ComponentArray componentArray[MAX_COMPONENTS];
	std::vector<std::unique_ptr<System>> systems;
};

//template<typename ComponentType>
//inline Component* World::GetComponents()
//{
//	;
//}

template<class ComponentType>
inline Component* World::GetComponents()
{
	return componentArray[ComponentHelper::GetComponentID<ComponentType>()].components;
}
