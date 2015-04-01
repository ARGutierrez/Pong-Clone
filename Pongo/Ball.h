#include "Entity.h"

class Ball : public Entity
{
public:
	Ball();
	void Update(sf::RenderWindow* window);
	void Reinit(sf::RenderWindow* window);

private:

};