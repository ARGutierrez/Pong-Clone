#include "Ball.h"
#include "Paddle.h"

bool quitGame = false;

const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
sf::Time timeSinceLastUpdate = sf::Time::Zero;

void ProcessEvents(sf::RenderWindow&);
void Update();
void Render();

int main()
{
	// Init screen
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setVerticalSyncEnabled(true);

	// Init ball
	Ball ball(window);

	// Init paddles
	Paddle player1(window, ball, -1);
	Paddle player2(window, ball, 1);

	sf::Clock gameClock;
	sf::Time time;

	while (window.isOpen())
	{
		sf::Time deltaTime = gameClock.restart();
		timeSinceLastUpdate += deltaTime;

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			ProcessEvents(window);
			ball.Update();
			player1.Update();
			player2.Update();
		}

		window.clear(sf::Color::Black);
		ball.Render();
		player1.Render();
		player2.Render();
		window.display();

		if (quitGame)
		{
			// Clean up
			ball.Destroy();
			player1.Destroy();
			player2.Destroy();
			window.close();
		}
	}

	return 0;
}

void ProcessEvents(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Update()
{
	
}

void Render()
{
	
}
