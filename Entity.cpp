#include "Entity.h"

Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f)); // placeholder
	this->shape.setFillColor(sf::Color::White);

	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::update(const float& dt) {
	// downwards is positive

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->move(dt, 0.f, -1.f); // up
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(dt, -1.f, 0.f); // left
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->move(dt, 0.f, 1.f); // down
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(dt, 1.f, 0.f); // right
	}
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}
