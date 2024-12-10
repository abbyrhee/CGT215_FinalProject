#include "Paddle.h"

using namespace sf;

Paddle::Paddle(RectangleShape& shape) {
	this->shape = shape;
}
Paddle::Paddle(Vector2f position, Vector2f size, Color color, int windowSize) {
	this->shape.setPosition(position);
	this->shape.setSize(size);
	this->shape.setFillColor(color);
	this->windowSize = windowSize;
}
void Paddle::Update(float deltaTime) {
	velocity = 0.f;
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		velocity = -speed * deltaTime;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		velocity = speed * deltaTime;
	}
	shape.move(velocity, 0.f);

	if (shape.getPosition().x < 0) {
		shape.setPosition(0, shape.getPosition().y);
	}
	else if (shape.getPosition().x + shape.getGlobalBounds().width > windowSize) {
		shape.setPosition(windowSize - shape.getGlobalBounds().width, shape.getPosition().y);
	}

}
