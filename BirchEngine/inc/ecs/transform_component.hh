#pragma once
#include "components.hh"
#include "../vector2D.hh"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent();

	TransformComponent(float x, float y);

	TransformComponent(float x, float y, int sc);

	void init() override;
	void update() override;
};