#pragma once
#include "CoreMinimal.h"
#include <type_traits>
#include <concepts>
#include "Components.h"

#define RETURN_NEGATIVE false

class ComponentHelper {
private:
	inline static ecs_numeric componentCounter = 0;

public:
	template<class ComponentType, typename = std::enable_if_t<std::is_base_of_v<Component, ComponentType>>>
	static ecs_numeric GetComponentID()
	{
		
		static ecs_numeric id = componentCounter++;

#ifdef RETURN_NEGATIVE
		//Returns negative if component id exceeds MAX_COMPONENTS
		return id + -(MAX_COMPONENTS + 1) * (id / MAX_COMPONENTS);
#else
		return id;
#endif
	}
};