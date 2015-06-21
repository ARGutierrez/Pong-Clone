#include "Ball.h"

Ball::Ball(sf::RenderWindow& window)
{
	this->m_window = &window;
	Init();
}

Ball::~Ball()
{
	Destroy();
}

void Ball::Init()
{
	srand(time(NULL));

	m_speed = k_initialSpeed;
	m_velocity = sf::Vector2f(0.0f, 0.0f);

	m_ball = new sf::CircleShape();
	m_ball->setFillColor(sf::Color::White);
	m_ball->setRadius(5.0f);
	m_ball->setPosition(m_window->getSize().x / 2 - m_ball->getGlobalBounds().width, m_window->getSize().y / 2 - m_ball->getGlobalBounds().height);
}

void Ball::Update()
{
	m_ball->move(m_velocity);

	// Start game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		StartGame();
	}

	// Floor and Ceiling collisions
	if (m_ball->getPosition().y <= 0)
	{
		m_velocity.y *= -1.0f;
	}
	if (m_ball->getPosition().y + m_ball->getGlobalBounds().height >= m_window->getSize().y)
	{
		m_velocity.y *= -1.0f;
	}

	// Scoring
	if (m_ball->getPosition().x < 0.0f)
	{
		// Player 2 scores
		// score2++;
		Reset();
	}
	if (m_ball->getPosition().x > m_window->getSize().x)
	{
		// Player 1 scores
		// score1++;
		Reset();
	}
}

void Ball::Render()
{
	m_window->draw(*m_ball);
}

void Ball::StartGame()
{
	m_velocity.y = ((rand() % 2) == 0) ? m_speed : -m_speed;
	m_velocity.x = ((rand() % 2) == 0) ? m_speed : -m_speed;
}

void Ball::Hit()
{
	m_speed += 0.35f;
}

void Ball::Reset()
{
	m_ball->setPosition(m_window->getSize().x / 2 - m_ball->getGlobalBounds().width, m_window->getSize().y / 2 - m_ball->getGlobalBounds().height);
	m_velocity = sf::Vector2f(0.0f, 0.0f);
	m_speed = k_initialSpeed;
}

void Ball::Destroy()
{
	m_speed = 0.0f;
	delete m_ball;
}

sf::FloatRect Ball::GetGlobalBounds()
{
	return m_ball->getGlobalBounds();
}
sf::Vector2f Ball::GetPosition()
{
	return m_ball->getPosition();
}

float Ball::GetSpeed()
{
	return m_speed;
}

