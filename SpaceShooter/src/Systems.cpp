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
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (worldContext->GetEntities()[i].HasComponents(componentMask))
		{
			Position* posComponent = static_cast<Position*>(&worldContext->GetComponents<Position>()[i]);
			Velocity* velComponent = static_cast<Velocity*>(&worldContext->GetComponents<Velocity>()[i]);

			posComponent->x += velComponent->xVel * Engine::Time::deltaTime;
			posComponent->y += velComponent->yVel * Engine::Time::deltaTime;
		}
	}
}
