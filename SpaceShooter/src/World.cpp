#include "World.h"
#include <iostream>
#include "ComponentHelper.h"
#include "Components.h"

World::World()
{
	std::cout << "pos: " << ComponentHelper::GetComponentID<Position>() << std::endl;
	std::cout << "vel: " << ComponentHelper::GetComponentID<Velocity>() << std::endl;
}

World::~World()
{

}
