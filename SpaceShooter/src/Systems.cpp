#include "Systems.h"
#include "World.h"
#include "Components.h"
#include "ComponentHelper.h"
#include "ComponentArray.h"
#include <Engine/Time.h>


void System::HandleLogic(World* worldContext) {}

MoveBullets::MoveBullets()
{
	System::SetMask<Bullet, Position, Velocity>();
}

void MoveBullets::HandleLogic(World* worldContext)
{
	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++)
	{
		if (worldContext->GetEntities()[i].HasComponents(componentMask))
		{
			Position* posComponent = worldContext->GetComponent<Position>(i);//  static_cast<Position*>(&worldContext->GetComponents<Position>()[i]);
			Velocity* velComponent = worldContext->GetComponent<Velocity>(i);
//Velocity* velComponent = static_cast<Velocity*>(&worldContext->GetComponents<Velocity>()[i]);

			std::cout << "x: " << posComponent->x << ", y: " << posComponent->y << std::endl;

			posComponent->x += velComponent->xVel * Engine::Time::deltaTime;
			posComponent->y += velComponent->yVel * Engine::Time::deltaTime;
		}
	}
}
