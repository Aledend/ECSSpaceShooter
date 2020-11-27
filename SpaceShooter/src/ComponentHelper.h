#pragma once
#include "CoreMinimal.h"
#include <type_traits>
#include <concepts>
#include "Components.h"

class ComponentHelper {
private:
	inline static ecs_numeric componentCounter = 0;

public:
	template<class T, typename = std::enable_if_t<std::is_base_of_v<Component, T>>>
	static ecs_numeric GetComponentID()
	{
		//Returns negative if component id exceeds MAX_COMPONENTS
		static ecs_numeric id = componentCounter++;
		return id + -(MAX_COMPONENTS + 1) * (id / MAX_COMPONENTS);
	}
};