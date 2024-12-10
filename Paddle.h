#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Paddle
{
public:
	RectangleShape shape;
	float velocity = 0.f;
	float speed = 400;
private:
	int windowSize = 0.f;
public:
	Paddle(RectangleShape& shape);
	Paddle(Vector2f position, Vector2f size, Color color, int windowSize);
	void Update(float deltaTime);
};

