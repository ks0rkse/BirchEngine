#include "ecs/sprite_component.hh"
#include "texture_manager.hh"

SpriteComponent::SpriteComponent(const char *path) {
    setTex(path);
}

SpriteComponent::SpriteComponent(const char *path, bool isAnimated) {
    animated = isAnimated;

    Animation idle = Animation(0, 3, 100);
    Animation walk = Animation(1, 8, 100);

    animations.emplace("Idle", idle);
    animations.emplace("Walk", walk);

    Play("Idle");

    setTex(path);
}

SpriteComponent::~SpriteComponent() {
    SDL_DestroyTexture(texture);
}

void SpriteComponent::init() {

    transform = &entity->getComponent<TransformComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;
}

void SpriteComponent::update() {
    if (animated)
    {
        srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    }

    srcRect.y = animIndex * transform->height;

    destRect.x = static_cast<int>(transform->position.x - Game::cameraOffset.x);
    destRect.y = static_cast<int>(transform->position.y - Game::cameraOffset.y);
    destRect.w = transform->width * transform->scale;
    destRect.h = transform->height * transform->scale;
}

void SpriteComponent::draw() {
    TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
}

void SpriteComponent::Play(const char *animName) {
    frames = animations[animName].frames;
    animIndex = animations[animName].index;
    speed = animations[animName].speed;
}

void SpriteComponent::setTex(const char *path) {
    texture = TextureManager::LoadTexture(path);
}
