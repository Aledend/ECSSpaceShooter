#pragma once
#include "Components.h"
#include "World.h"
#include "CoreMinimal.h"


class EntityHelper {
public:
	static inline ecs_numeric ReserveBullet(World* worldContext)
	{
		return worldContext->CreateEntity<Bullet, Position, Velocity, Sprite>();
	}

	// With sprite and stuff at the same time.
	/*ecs_numeric CreateBullet(World* worldContext)
	{
		return worldContext->CreateEntity<Bullet, Position, Velocity, Sprite>();
	}*/

	static inline ecs_numeric ReservePlayer(World* worldContext)
	{
		return worldContext->CreateEntity<Player, Position, Velocity, Sprite>();
	}
};