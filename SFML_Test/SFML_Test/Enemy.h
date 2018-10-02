#pragma once
#ifndef ENEMY
#define ENEMY
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
public:
	Enemy(sf::Vector2f pos, int type);
	~Enemy();
	void update(sf::Vector2f targetPos);
	void draw(sf::RenderWindow & window);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	float m_speed;
	int m_type;

	void boundaryCheck();
	void movement();
	void kinematicWander(sf::Vector2f targetPos);
	void kinematicSeek(sf::Vector2f targetPos);
	void kinematicArrive(sf::Vector2f targetPos);
	void kinematicFlee(sf::Vector2f targetPos);

	sf::Vector2f normalize(sf::Vector2f vel);
	float length(sf::Vector2f vel);
	float getNewOrientation(float orientation, sf::Vector2f vel);

	const float m_maxRotation = 360.0f;
	const float m_maxSpeed = 0.25f;
	const float m_timeToTarget = 1000.0f;
};

#endif