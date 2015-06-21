#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\Graphics.hpp>

class Entity
{
protected:
	sf::Vector2f m_velocity;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Reset() = 0;
	virtual void Destroy() = 0;

public:
	sf::Vector2f GetVelocity()
	{
		return m_velocity;
	}

	void SetVelocity(sf::Vector2f vel)
	{
		m_velocity = vel;
	}
};
#endif