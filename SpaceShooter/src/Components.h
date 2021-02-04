#pragma once
#include "CoreMinimal.h"
#include "SDL_image.h"

class World;

class Component 
{ 
public:
	Component();
};


class Velocity : public Component
{
public:
	float xVel;
	float yVel;

	void Set(float xVel, float yVel);

	void Reset();
};

class Position : public Component
{
public:
	Position();
	float x;
	float y;


	void Set(float x, float y);

	void Reset(); 
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
	void Set(float radius);
};

class Keyboard : Component {};