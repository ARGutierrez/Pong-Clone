#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>
#include <iostream>

#include "Ball.h"

bool quitGame = false;

sf::Vector2f paddleVelocity(0.0f, 5.0f);

float initialBallSpeed = 3.0f;
float ballSpeed = 3.0f;

int score1 = 0;
int score2 = 0;

void ResetBall(sf::RenderWindow& window, sf::RectangleShape& ball);
void HitPaddle(sf::RectangleShape& paddle, sf::RectangleShape& ball, int playerIndex);

int main()
{
	srand(time(NULL));

	// Init screen
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setVerticalSyncEnabled(true);

	// Init ball
	Ball ball(window);

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

		// Start game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			ball.Reset();
		}

		// Update the ball and paddles

		ball.Update();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			paddle1.move(-paddleVelocity);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			paddle1.move(paddleVelocity);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			paddle2.move(-paddleVelocity);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			paddle2.move(paddleVelocity);
		}

		// Ball movement and collisions

		

		// Paddle collisions with ball
		/*HitPaddle(paddle1, shape, -1);
		HitPaddle(paddle2, shape,  1);*/

		


		// Render the ball and paddles
		
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

//void ResetBall(sf::RenderWindow& window, sf::RectangleShape& ball)
//{
//	ball.setPosition(window.getSize().x / 2 - ball.getGlobalBounds().width / 2, window.getSize().y / 2 - ball.getGlobalBounds().height / 2);
//	ballVelocity.x = ballSpeed;
//	ballVelocity.y = ((rand() % 2) == 0) ? ballSpeed : -ballSpeed;
//}

// player index: -1 for left, 1 for right
//void HitPaddle(sf::RectangleShape& paddle, sf::RectangleShape& ball, int playerIndex)
//{
//	if (paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
//	{
//		// Calculate collision in paddle's local space
//		float hitPoint = paddle.getPosition().y + (paddle.getGlobalBounds().height / 2) - ball.getPosition().y;
//		float normalizedHitPoint = (hitPoint / (paddle.getGlobalBounds().height / 2));
//		// 5pi / 12
//		float angle = normalizedHitPoint * (5.0f * 3.14f) / 12.0f;
//
//		ballVelocity.x = ballSpeed * cos(angle) * playerIndex;
//		ballVelocity.y = -ballSpeed * sin(angle);
//
//		ballSpeed += 0.15f;
//		ballVelocity.x *= -1.5f;
//	}
//}