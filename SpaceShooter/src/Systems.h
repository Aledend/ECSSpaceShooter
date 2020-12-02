#pragma once
#include "CoreMinimal.h"
#include <bitset>
#include "ComponentHelper.h"
class World;

class System {
public:
	template<class ...RequiredComponents>
	void SetMask();
	virtual void HandleLogic(World* worldContext);
protected:
	std::bitset<MAX_COMPONENTS> componentMask;
};


class MoveBullets : public System {
public:
	MoveBullets();


	void HandleLogic(World* worldContext) override;

};


template<class ...RequiredComponents>
inline void System::SetMask()
{
	(componentMask.set(ComponentHelper::GetComponentID<RequiredComponents>()), ...);
}