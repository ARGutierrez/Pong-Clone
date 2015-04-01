#include <SFML\Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	sf::Vector2f velocity;

	Entity()
	{
		texture = new sf::Texture();
	}

	~Entity()
	{
		delete texture;
	}

	void Load(std::string fileName)
	{
		texture->loadFromFile("Resources/Graphics/" + fileName);
		setTexture(*texture);
	}

	virtual void Update()
	{
		move(velocity);
	}

	bool CollisionCheck(Entity* entity)
	{
		return getGlobalBounds().intersects(entity->getGlobalBounds);
	}

private:
	sf::Texture* texture;
};