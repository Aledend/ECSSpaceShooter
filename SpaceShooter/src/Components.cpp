#pragma once
#include "Components.h"
#include <cassert>
#include "World.h"


Component::Component()
{
	
}

Position::Position()
{
	x = 0.f;
	y = 0.f;
}


Sprite::~Sprite()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Sprite::SetTexture(World* worldContext, const char* filePath)
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}

	texture = IMG_LoadTexture(worldContext->renderer, filePath);
	assert(texture, "Image from path could not be loaded onto texture.");

	//texture = SDL_CreateTextureFromSurface(worldContext->renderer, tempSurface);
	int w;
	int h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);



	textureRect.w = w;
	textureRect.h = h;
	textureRect.x = 0;
	textureRect.y = 0;

}
