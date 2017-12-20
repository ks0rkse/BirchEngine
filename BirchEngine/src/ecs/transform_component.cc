#include "ecs/transform_component.hh"

TransformComponent::TransformComponent() {
    position.Zero();
}

TransformComponent::TransformComponent(float x, float y) {
    position.Zero();
}

TransformComponent::TransformComponent(float x, float y, int sc) {
    position.x = x;
    position.y = y;
    scale = sc;
}

void TransformComponent::init() {
    velocity.Zero();
}

void TransformComponent::update() {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}
