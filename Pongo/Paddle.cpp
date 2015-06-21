#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow& window, Ball& ball, int player)
{
	this->m_window = &window;
	this->m_ball = &ball;

	m_playerIndex = player;

	Init();
}

Paddle::~Paddle()
{
	Destroy();
}

void Paddle::Init()
{
	m_speed = k_initialSpeed;
	m_velocity = sf::Vector2f(0.0f, m_speed);

	m_paddle = new sf::RectangleShape();
	m_paddle->setFillColor(sf::Color::White);
	m_paddle->setSize(sf::Vector2f(20.0f, 100.0f));
	if (m_playerIndex == -1)
	{
		m_paddle->setPosition(sf::Vector2f(20.0f, m_window->getSize().y / 2 - m_paddle->getGlobalBounds().height / 2));
	}
	else
	{
		m_paddle->setPosition(sf::Vector2f(m_window->getSize().x - 40.0f, m_window->getSize().y / 2 - m_paddle->getGlobalBounds().height / 2));
	}
}

void Paddle::Update()
{
	if (m_playerIndex == -1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_paddle->move(-m_velocity);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_paddle->move(m_velocity);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_paddle->move(-m_velocity);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_paddle->move(m_velocity);
		}
	}

	if (m_paddle->getGlobalBounds().intersects(m_ball->GetGlobalBounds()))
	{
		// Calculate collision in paddle's local space
		float hitPoint = m_paddle->getPosition().y + (m_paddle->getGlobalBounds().height / 2) - m_ball->GetPosition().y;
		float normalizedHitPoint = (hitPoint / (m_paddle->getGlobalBounds().height / 2));
		// 5pi / 12
		float angle = normalizedHitPoint * (5.0f * 3.14f) / 12.0f;
		
		sf::Vector2f newBallVelocity(0.0f, 0.0f);
		newBallVelocity.x = m_ball->GetSpeed() * cos(angle) * m_playerIndex * -1.5f;
		newBallVelocity.y = -m_ball->GetSpeed() * sin(angle);
		m_ball->SetVelocity(newBallVelocity);
		m_ball->Hit();
	}
}

void Paddle::Render()
{
	m_window->draw(*m_paddle);
}


void Paddle::Reset()
{
	m_speed = k_initialSpeed;
}

void Paddle::Destroy()
{
	delete m_paddle;
}