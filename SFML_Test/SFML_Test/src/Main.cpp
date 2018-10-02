#include <iostream>
#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Enemy.h"
#define M_PI           3.14159265//358979323846  /* pi */

int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
	
	std::unique_ptr<Player> m_player = std::make_unique<Player>();
	std::unique_ptr<Enemy> m_enemyWander = std::make_unique<Enemy>(sf::Vector2f(1000.0f, 800.0f), 0);
	std::unique_ptr<Enemy> m_enemyArrive = std::make_unique<Enemy>(sf::Vector2f(1000.0f, 400.0f), 1);
	std::unique_ptr<Enemy> m_enemyFlee = std::make_unique<Enemy>(sf::Vector2f(250.0f, 250.0f), 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		m_player->update();
		m_enemyWander->update(m_player->getPos());
		m_enemyArrive->update(m_player->getPos());
		m_enemyFlee->update(m_player->getPos());

		window.clear();
		m_player->draw(window);
		m_enemyWander->draw(window);
		m_enemyArrive->draw(window);
		m_enemyFlee->draw(window);
		window.display();
	}


	return 0;
}