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
	m_speed = 0.0f;
	m_velocity = sf::Vector2f(0.0f, 0.0f);

	m_ball = new sf::RectangleShape();
	m_ball->setFillColor(sf::Color::White);
	m_ball->setSize(sf::Vector2f(10.f, 10.f));
	m_ball->setPosition(m_window->getSize().x / 2 - m_ball->getGlobalBounds().width, m_window->getSize().y / 2 - m_ball->getGlobalBounds().height);
}

void Ball::Update()
{
	m_ball->move(m_velocity);
	m_window->draw(*m_ball);

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

void Ball::Reset()
{
	m_ball->setPosition(m_window->getSize().x / 2 - m_ball->getGlobalBounds().width, m_window->getSize().y / 2 - m_ball->getGlobalBounds().height);
	m_velocity = sf::Vector2f(0.0f, 0.0f);
}

void Ball::Destroy()
{
	m_speed = 0.0f;
	delete m_ball;
}