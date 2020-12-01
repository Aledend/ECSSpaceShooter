#pragma once
#include "CoreMinimal.h"


//typedef int uint8_t;



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
};

class Position : public Component
{
public:
	Position();
	float x;
	float y;
};

class Player : Component {};

class Enemy : Component {};

class Bullet : Component {};

class Sprite : Component {
	// Sprite
};

class CircleCollider : Component {

};
