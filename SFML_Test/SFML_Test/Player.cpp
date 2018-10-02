#include "Player.h"

Player::Player()
{
	m_pos = sf::Vector2f(200.0f, 200.0f);
	m_sprite.setPosition(m_pos);

	if (!m_texture.loadFromFile("Sprite/Spaceship.png"))
	{
		// Error
	};
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(0.5f, 0.5f);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2.0f, m_sprite.getLocalBounds().height / 2.0f));
	m_speed = 0.1f;
	m_rotSpeed = 0.25f;
}

Player::~Player()
{

}

void Player::update()
{
	movement();
	boundaryCheck();
	
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Player::boundaryCheck()
{
	if (m_pos.x > 2075.0f)
	{
		m_pos.x = -160.0f;
	}
	else if (m_pos.x < -160.0f)
	{
		m_pos.x = 2000.0f;
	}
	else if (m_pos.y > 1075.0f)
	{
		m_pos.y = -160.0f;
	}
	else if (m_pos.y < -160.0f)
	{
		m_pos.y = 1000.0f;
	}

	m_sprite.setPosition(m_pos);
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_pos.x = m_pos.x + (m_speed * 4) * (std::cos(m_sprite.getRotation() * M_PI / 180.0f));
		m_pos.y = m_pos.y + (m_speed * 4) * (std::sin(m_sprite.getRotation() * M_PI / 180.0f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.setRotation(m_sprite.getRotation() + m_rotSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.setRotation(m_sprite.getRotation() - m_rotSpeed);
	}
}

sf::Vector2f Player::getPos()
{
	return m_pos;
}