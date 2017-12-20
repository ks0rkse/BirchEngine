#pragma once

#include "components.hh"

class KeyboardController : public Component
{
public:
	TransformComponent *transform;
	SpriteComponent *sprite;

	void init() override;
	void update() override;
};