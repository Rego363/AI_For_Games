#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, int type)
{
	m_type = type;
	m_pos = pos;
	m_sprite.setPosition(m_pos);
	m_sprite.setRotation(180.0f);


	if (!m_texture.loadFromFile("Sprite/Enemyship.png"))
	{
		// Error
	};
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(0.5f, 0.5f);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2.0f, m_sprite.getLocalBounds().height / 2.0f));
	m_speed = 0.1f;
	m_velocity = sf::Vector2f(0, 0);
}

Enemy::~Enemy()
{

}

void Enemy::update(sf::Vector2f targetPos)
{
	if (m_type == 0)
	{
		kinematicWander(targetPos);
	}
	else if (m_type == 1)
	{
		kinematicArrive(targetPos);
	}
	else
	{

		kinematicFlee(targetPos);
	}

	boundaryCheck();
	
	m_sprite.setPosition(m_pos);
}

void Enemy::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Enemy::boundaryCheck()
{
	if (m_pos.x > 2250.0f)
	{
		m_pos.x = -160.0f;
	}
	else if (m_pos.x < -160.0f)
	{
		m_pos.x = 2000.0f;
	}
	else if (m_pos.y > 1250.0f)
	{
		m_pos.y = -160.0f;
	}
	else if (m_pos.y < -160.0f)
	{
		m_pos.y = 1000.0f;
	}

	m_sprite.setPosition(m_pos);
}

void Enemy::movement()
{
	m_pos.y += m_speed;
}

void Enemy::kinematicWander(sf::Vector2f targetPos)
{
	m_velocity = targetPos - m_pos;
	m_velocity = normalize(m_velocity);
	float orientation = getNewOrientation(m_sprite.getRotation(), m_velocity);
	orientation = orientation + m_maxRotation * ((rand() % 2) - 1);
	m_sprite.setRotation(orientation);
	m_velocity = sf::Vector2f(-sin(orientation), cos(orientation)) * m_maxSpeed;
	m_pos += m_velocity;
}

void Enemy::kinematicSeek(sf::Vector2f targetPos)
{
	m_velocity = normalize(m_velocity);
	m_velocity = m_velocity * m_maxSpeed;
}

void Enemy::kinematicArrive(sf::Vector2f targetPos)
{
	m_velocity = targetPos - m_pos;

	m_velocity = m_velocity / m_timeToTarget;

	if(length(m_velocity) > m_maxSpeed)
	{
		kinematicSeek(targetPos);
	}
	float orientation = getNewOrientation(m_sprite.getRotation(), m_velocity);
	m_sprite.setRotation(orientation);
	m_pos += m_velocity;
}

void Enemy::kinematicFlee(sf::Vector2f targetPos)
{
	m_velocity = m_pos - targetPos;
	m_velocity = normalize(m_velocity);
	m_velocity *= m_maxSpeed;
	float orientation = getNewOrientation(m_sprite.getRotation(), m_velocity);
	m_sprite.setRotation(orientation);
	m_pos += m_velocity;
}

float Enemy::getNewOrientation(float orientation, sf::Vector2f vel)
{
	if (length(vel) > 0.0f)
	{
		return (atan2(-vel.x, vel.y) * (180.0 / 3.141592653589793238463));
	}
	else
	{
		return orientation;
	}
}

float Enemy::length(sf::Vector2f vel)
{
	return (sqrt((vel.x * vel.x) + (vel.y * vel.y)));
}

sf::Vector2f Enemy::normalize(sf::Vector2f vel)
{
	if (length(vel) != 0)
		return sf::Vector2f(vel.x / length(vel), vel.y / length(vel));
	else
		return vel;
}