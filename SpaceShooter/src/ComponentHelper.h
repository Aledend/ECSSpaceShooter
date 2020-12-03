#pragma once
#include "CoreMinimal.h"
#include <type_traits>
#include <concepts>
#include "Components.h"

class ComponentHelper {
private:
	inline static ecs_numeric componentCounter = 0;

public:
	template<class ComponentType, typename = std::enable_if_t<std::is_base_of_v<Component, ComponentType>>>
	static ecs_numeric GetComponentID()
	{
		static ecs_numeric id = componentCounter++;
		return id;
	}
};