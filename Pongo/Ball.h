#ifndef BALL_H
#define BALL_H
#include "Entity.h"

class Ball : public Entity
{
public:

	void Init();
	void Update();
	void Reset();
	void Destroy();

	void StartGame();
	void Hit();

	sf::FloatRect GetGlobalBounds();
	sf::Vector2f GetPosition();
	float GetSpeed();

	Ball(sf::RenderWindow&);
	~Ball();

private:
	float m_speed;
	const float k_initialSpeed = 3.0f;

	sf::CircleShape* m_ball;
	sf::RenderWindow* m_window;
};
#endif