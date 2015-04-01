#include <SFML/Graphics.hpp>

bool quitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong RPG");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		// Update and Render go here

		if (quitGame)
		{
			window.close();
		}
	}

	return 0;
}