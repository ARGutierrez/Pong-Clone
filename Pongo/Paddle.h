#ifndef PADDLE_H
#define PADDLE_H
#include "Ball.h"

class Paddle : public Entity
{
public:

	void Init();
	void Update();
	void Render();
	void Reset();
	void Destroy();

	Paddle(sf::RenderWindow&, Ball&, int);
	~Paddle();

private:
	float m_speed;
	const float k_initialSpeed = 5.0f;

	int m_playerIndex;

	sf::RectangleShape* m_paddle;
	Ball* m_ball;
	sf::RenderWindow* m_window;
};
#endif