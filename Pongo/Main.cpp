#include <SFML/Graphics.hpp>

bool quitGame = false;

sf::Vector2f paddleVelocity(0.0f, 2.0f);

int main()
{
	// Init screen
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setVerticalSyncEnabled(true);

	// Init ball
	sf::RectangleShape shape(sf::Vector2f(10.0f, 10.0f));
	shape.setFillColor(sf::Color::White);
	shape.setPosition(window.getSize().x / 2 - shape.getGlobalBounds().width / 2, window.getSize().y / 2 - shape.getGlobalBounds().height / 2);

	// Init paddles
	sf::RectangleShape paddle1(sf::Vector2f(20.0f, 100.0f));
	paddle1.setFillColor(sf::Color::White);
	paddle1.setPosition(sf::Vector2f(20.0f, window.getSize().y / 2 - paddle1.getGlobalBounds().height / 2));

	sf::RectangleShape paddle2(sf::Vector2f(20.0f, 100.0f));
	paddle2.setFillColor(sf::Color::White);
	paddle2.setPosition(sf::Vector2f(800.0f - 20.0f - 20.0f, window.getSize().y / 2 - paddle2.getGlobalBounds().height / 2));

	sf::Time time;
	// float rot = 0.05f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		// Clear the screen before we update and draw
		window.clear(sf::Color::Black);

		// Update the ball and paddles
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			paddle1.move(paddleVelocity);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			paddle1.move(-paddleVelocity);
		}
		shape.move(sf::Vector2f(0.1f, 0.1f));
		// Render the ball and paddles
		window.draw(shape);
		window.draw(paddle1);
		window.draw(paddle2);

		window.display();

		// sf::sleep(sf::seconds(1));

		if (quitGame)
		{
			window.close();
		}
	}

	return 0;
}