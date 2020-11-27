#pragma once
#include "CoreMinimal.h"
#include "Components.h"
#include <bitset>
#include <iostream>
#include <type_traits>
#include "ComponentHelper.h"

class Entity {

private:
	std::bitset<MAX_COMPONENTS> components;

public:

	/*Entity()
	{

	}*/

	template<class T>
	bool HasComponent() const
	{
		return this->components.test(ComponentHelper::GetComponentID<T>());
	}

	template<class... Args>
	bool HasComponents() const
	{
		return this->components.test(ComponentHelper::GetComponentID<Args...>());
	}

	template<class T>
	inline void AddComponent()
	{
		this->components.set(ComponentHelper::GetComponentID<T>(), true);
	}

	template<class ...Args>
	inline void AddComponents()
	{
		components.set((ComponentHelper::GetComponentID<Args>(), ...), true);
	}

	template<class T>
	inline void RemoveComponent()
	{
		this->components.set(ComponentHelper::GetComponentID<T>(), false);
	}

	template<class... Args>
	inline void RemoveComponent()
	{
		this->components.set((ComponentHelper::GetComponentID<Args>(), ...), false);
	}
};