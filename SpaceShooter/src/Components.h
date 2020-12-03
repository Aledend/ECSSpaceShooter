#pragma once
#include "CoreMinimal.h"
#include "SDL_image.h"

class World;

class Component 
{ 
public:
	Component();
	//virtual ~Component() = default;
};


class Velocity : public Component
{
public:
	float xVel;
	float yVel;

	void Set(float xVel, float yVel) {
		this->xVel = xVel;
		this->yVel = yVel;
	}

	void Reset() {
		xVel = 0.f;
		yVel = 0.f;
	}
};

class Position : public Component
{
public:
	Position();
	float x;
	float y;

	void Reset() {
		x = 0.f;
		y = 0.f;
	}

	void Set(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

class Player : Component {};

class Enemy : Component {};

class Bullet : Component {};

class Sprite : Component {
public:
	~Sprite();
	SDL_Texture* texture = nullptr;
	SDL_Rect textureRect;
	void SetTexture(World* worldContext, const char* filePath);
};

class CircleCollider : Component {
public:
	float radius;
	void Set(float radius)
	{
		this->radius = radius;
	}
};

class Keyboard : Component {};