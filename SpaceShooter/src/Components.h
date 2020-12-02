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

	void Set(float _x, float _y) {
		x = _x;
		y = _y;
	}
};

class Player : Component {};

class Enemy : Component {};

class Bullet : Component {};

class Sprite : Component {
	// Sprite
};

class CircleCollider : Component {

};
