#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
	
	// Triangle class
	sf::CircleShape tri(80.f, 3);
	sf::Vector2f triPos = sf::Vector2f(200.0f, 200.0f);
	tri.setPosition(triPos);
	tri.setFillColor(sf::Color::Green);

	// Rect class
	sf::RectangleShape rect(sf::Vector2f(160.0f, 80.0f));
	sf::Vector2f rectPos = sf::Vector2f(500.0f, 500.0f);
	rect.setPosition(rectPos);
	rect.setFillColor(sf::Color::Blue);

	float speed = 0.1f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		triPos.y += speed;	// Move triangle down
		if (triPos.y > 1000)
		{
			triPos.y = -160.0f;
		}
		tri.setPosition(triPos);

		// Move rectangle right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rectPos.x += speed * 4;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rectPos.x += speed / 4;
		}
		else
		{
			rectPos.x += speed;
		}

		if (rectPos.x > 2000)
		{
			rectPos.x = -160.0f;
		}
		rect.setPosition(rectPos);

		window.clear();
		window.draw(tri);
		window.draw(rect);
		window.display();
	}


	return 0;
}