#pragma once
#include "CoreMinimal.h"
#include <bitset>
#include "ComponentHelper.h"
class World;

class System {
public:
	virtual void HandleLogic(World* worldContext);
protected:
	template<class ...RequiredComponents>
	void SetMask();
	std::bitset<MAX_COMPONENTS> componentMask;
};


class MovePlayers : public System {
public:
	MovePlayers();

	void HandleLogic(World* worldContext) override;
};

class Render : public System {
public:
	Render();

	void HandleLogic(World* worldContext) override;
};

//class UpdateInput : public System {
//public:
//	UpdateInput();
//
//	void HandleLogic(World* worldContext) override;
//};

class ControlPlayers : public System {
public:
	ControlPlayers();

	void HandleLogic(World* worldContext) override;
};


template<class ...RequiredComponents>
inline void System::SetMask()
{
	(componentMask.set(ComponentHelper::GetComponentID<RequiredComponents>()), ...);
}