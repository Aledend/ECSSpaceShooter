#include <Engine.h>

class SpaceShooter : public Engine::Application
{
public:
	SpaceShooter()
	{

	}

	~SpaceShooter()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new SpaceShooter();
}