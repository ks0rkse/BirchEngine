#include "ecs/tile_component.hh"
#include "texture_manager.hh"

TileComponent::TileComponent(int srcX, int srcY, int xpos, int ypos, const char *path) {
    texture = TextureManager::LoadTexture(path);

    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcRect.h = 32;
    position.x = xpos;
    position.y = ypos;
    destRect.w = destRect.h = 64;
}

void TileComponent::update() {
    destRect.x = position.x - Game::cameraOffset.x;
    destRect.y = position.y - Game::cameraOffset.y;
}

void TileComponent::draw() {
    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
}

TileComponent::~TileComponent() {
    SDL_DestroyTexture(texture);
}
