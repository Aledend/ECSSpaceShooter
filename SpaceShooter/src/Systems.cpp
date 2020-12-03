#include "Systems.h"
#include "World.h"
#include "Components.h"
#include "ComponentHelper.h"
#include "ComponentArray.h"
#include <Engine/Time.h>
#include "SDL.h"


void System::HandleLogic(World* worldContext) {}

MovePlayers::MovePlayers()
{
	System::SetMask<Player, Position, Velocity>();
}

void MovePlayers::HandleLogic(World* worldContext)
{
	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++) 
	{
		if (worldContext->GetEntities()[i].HasComponents(componentMask))
		{
			Position* posComponent = worldContext->GetComponent<Position>(i);
			Velocity* velComponent = worldContext->GetComponent<Velocity>(i);

			posComponent->x += velComponent->xVel * Engine::Time::deltaTime;
			posComponent->y += velComponent->yVel * Engine::Time::deltaTime;
		}
	}
}

Render::Render()
{
	SetMask<Sprite, Position>();
}

void Render::HandleLogic(World* worldContext)
{
	SDL_RenderClear(worldContext->renderer);
	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++)
	{
		if (worldContext->GetEntities()[i].HasComponents(componentMask))
		{
			Sprite* spriteComponent = worldContext->GetComponent<Sprite>(i);
			Position* posComponent = worldContext->GetComponent<Position>(i);

			SDL_Rect finalRect = { (int)posComponent->x, 
									(int)posComponent->y, 
									spriteComponent->textureRect.w, 
									spriteComponent->textureRect.h };

			SDL_RenderCopy(worldContext->renderer, spriteComponent->texture, &spriteComponent->textureRect, &finalRect);
		}
	}
	SDL_RenderPresent(worldContext->renderer);
}


ControlPlayers::ControlPlayers() {
	SetMask<Player, Velocity>();
}

void ControlPlayers::HandleLogic(World* worldContext)
{
	for (ecs_numeric i = 0; i < MAX_ENTITIES; i++)
	{
		if (worldContext->GetEntities()[i].HasComponents(componentMask))
		{
			float xVel = 0.f;
			float yVel = 0.f;

			if (worldContext->keyboard[SDL_SCANCODE_W])
			{
				yVel -= 1000.f * Engine::Time::deltaTime;
			}
			if (worldContext->keyboard[SDL_SCANCODE_S])
			{
				yVel += 1000.f * Engine::Time::deltaTime;
			}
			if (worldContext->keyboard[SDL_SCANCODE_D])
			{
				xVel += 1000.f * Engine::Time::deltaTime;
			}
			if (worldContext->keyboard[SDL_SCANCODE_A])
			{
				xVel -= 1000.f * Engine::Time::deltaTime;
			}

			Velocity* velComponent = worldContext->GetComponent<Velocity>(i);
			velComponent->xVel += xVel;
			velComponent->yVel += yVel;
		}
	}
}
