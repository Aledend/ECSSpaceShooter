#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "ComponentArray.h"
#include "Systems.h"
#include <vector>
#include <string>

class World {
public:
	World();
	~World();

	void Update();
	Entity* GetEntities();
private:
	Entity entities[MAX_ENTITIES];
	ComponentArray components[MAX_COMPONENTS];
	std::basic_string<System> systems;
};