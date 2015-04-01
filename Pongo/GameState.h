#include <SFML\Graphics.hpp>

class GameState
{
public:
	void Init(sf::RenderWindow* window)
	{
		if (state != NULL)
		{
			state->Update(window);
		}
	}
	virtual void Update(sf::RenderWindow* window)
	{
		if (state != NULL)
		{
			state->Update(window);
		}
	}
	virtual void Render(sf::RenderWindow* window)
	{
		if (state != NULL)
		{
			state->Render(window);
		}
	}
	virtual void Destroy(sf::RenderWindow* window)
	{
		if (state != NULL)
		{
			state->Destroy(window);
		}
	}

	GameState()
	{
		state = NULL;
	}

	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(GameState* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(window);
		}

		this->state = state;

		if (this->state != NULL)
		{
			this->state->Init(window);
		}
	}
private:
	sf::RenderWindow* window;
	GameState* state;
};

