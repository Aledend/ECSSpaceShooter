#pragma once

class SystemManager {
public:
	SystemManager(class World* worldContext);
	~SystemManager();
private:
	class World* world;
};