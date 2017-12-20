#pragma once

#include <string>
#include <SDL.h>

#include "components.hh"

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