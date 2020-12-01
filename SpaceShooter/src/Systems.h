#pragma once
#include "World.h"

class System {
public:
	virtual ~System() {}
	virtual void HandleLogic() {}
};

class MoveBullet : System {
public:
	void HandleLogic() override
	{
		//for(Entity e : worldContext->entities)
	}
};