#include "Ball.h"

Ball::Ball()
{
	Load("ball.png");
}

void Ball::Update(sf::RenderWindow* window)
{

}

void Ball::Reinit(sf::RenderWindow* window)
{
	velocity.x = 1.0f;
	int rnd = rand();
	velocity.y = ((rnd % 3) == 0) ? rnd + 1.0f : -rnd + 1.0f;
	setPosition(window->getSize().x / 2, window->getSize().y / 2);
}