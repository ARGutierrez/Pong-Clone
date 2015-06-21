#include <SFML\Graphics.hpp>

class Entity
{
protected:
	sf::Vector2f m_velocity;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Reset() = 0;
	virtual void Destroy() = 0;
};