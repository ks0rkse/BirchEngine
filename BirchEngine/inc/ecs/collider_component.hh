#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "ecs.hh"
#include "transform_component.hh"

class ColliderComponent : public Component
{
public:
	SDL_Rect collider;
	std::string tag;
	TransformComponent* transform;

	explicit ColliderComponent(std::string t);

	void init() override;
	void update() override;
};