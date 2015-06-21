#include <time.h>
#include <math.h>
#include <iostream>

#include "Ball.h"
#include "Paddle.h"

bool quitGame = false;

sf::Vector2f paddleVelocity(0.0f, 5.0f);

float initialBallSpeed = 3.0f;
float ballSpeed = 3.0f;

int score1 = 0;
int score2 = 0;

void ResetBall(sf::RenderWindow& window, sf::RectangleShape& ball);

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

	sf::Time time;

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

		ball.Update();
		player1.Update();
		player2.Update();
		
		// Render
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
