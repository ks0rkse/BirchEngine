#pragma once

#include "transform_component.hh"
#include "sprite_component.hh"

class KeyboardController : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

	void init() override;
	void update() override;
};