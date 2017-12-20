#pragma once

#include <SDL2/SDL.h>
#include <map>
#include "ecs.hh"
#include "animation.hh"
#include "transform_component.hh"

class SpriteComponent : public Component
{
public:
	int animIndex = 0;
	std::map<const std::string, Animation> animations;
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

private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frames = 0;
    int speed = 100;
};