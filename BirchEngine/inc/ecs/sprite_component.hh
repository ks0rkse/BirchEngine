#pragma once

#include "SDL.h"
#include <map>
#include "components.hh"
#include "../texture_manager.hh"
#include "animation.hh"

class SpriteComponent : public Component
{
private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:

	int animIndex = 0;
	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComponent() = default;
	explicit SpriteComponent(const char* path);
	SpriteComponent(const char* path, bool isAnimated);
	~SpriteComponent();

	void setTex(const char* path);

	void init() override;
	void update() override;
	void draw() override;

	void Play(const char* animName);
};