#include "Entity.h"

class Ball : public Entity
{
public:

	void Init();
	void Update();
	void Reset();
	void Destroy();

	Ball(sf::RenderWindow&);
	~Ball();

private:
	float m_speed;

	sf::RectangleShape* m_ball;
	sf::RenderWindow* m_window;
};