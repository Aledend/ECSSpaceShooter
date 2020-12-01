#pragma once
#include "CoreMinimal.h"


//typedef int uint8_t;



class Component 
{ 
	//virtual ~Component() = default;
};

class Position : Component
{
	float x;
	float y;
};

class Velocity : Component
{
	float xVel;
	float yVel;
};

class Player : Component {};

class Enemy : Component {};

