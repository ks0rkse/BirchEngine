#pragma once


#include <SDL2/SDL.h>
#include "ecs.hh"
#include "vector2D.hh"

class TileComponent : public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;
    TileComponent(int srcX, int srcY, int xpos, int ypos, const char* path);
	~TileComponent();

	void update() override;
	void draw() override;
};