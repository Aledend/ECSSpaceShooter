#pragma once
#include "Components.h"
#include "World.h"
#include "CoreMinimal.h"
#include <cstdlib>

class EntityHelper {
public:
	static inline ecs_numeric ReserveBullet(World* worldContext)
	{
		return worldContext->CreateEntity<Bullet, Position, Velocity, Sprite>();
	}

	// With sprite and stuff at the same time.
	static inline ecs_numeric CreateBullet(World* worldContext)
	{
		ecs_numeric entityID = worldContext->CreateEntity<Bullet, Position, Velocity, Sprite>();
		worldContext->GetComponent<Position>(entityID)->Set(400.f, 300.f);
		worldContext->GetComponent<Velocity>(entityID)->Set((rand() % 20001 - 10000) * 0.01f, (rand() % 20001 - 10000) * 0.01f);
		worldContext->GetComponent<Sprite>(entityID)->SetTexture(worldContext, "assets/sprites/Bullet.png");
		return entityID;
	}

	static inline ecs_numeric ReservePlayer(World* worldContext)
	{
		return worldContext->CreateEntity<Player, Position, Velocity, Sprite>();
	}

	static inline ecs_numeric CreatePlayer(World* worldContext)
	{
		ecs_numeric entityID = worldContext->CreateEntity<Player, Position, Velocity, Sprite>();
		worldContext->GetComponent<Position>(entityID)->Set(400.f, 300.f);
		worldContext->GetComponent<Velocity>(entityID)->Set((rand() % 20001 - 10000) * 0.01f, (rand() % 20001 - 10000) * 0.01f);
		worldContext->GetComponent<Sprite>(entityID)->SetTexture(worldContext, "assets/sprites/PlayerShip.png");
		return entityID;
	}

	/*static inline ecs_numeric CreateKeyboard(World* worldContext)
	{
		return worldContext->CreateEntity<Keyboard>();
	}*/
};