#include "ecs/collider_component.hh"
#include "game.hh"

void ColliderComponent::update() {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
}

void ColliderComponent::init() {
    if (!entity->hasComponent<TransformComponent>())
    {
        entity->addComponent<TransformComponent>();
    }

    transform = &entity->getComponent<TransformComponent>();

    Game::colliders.push_back(this);
}

ColliderComponent::ColliderComponent(std::string t) {
    tag = t;
}
