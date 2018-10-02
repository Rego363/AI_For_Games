#pragma once
#ifndef PLAYER
#define PLAYER
#include <SFML/Graphics.hpp>
#define M_PI           3.14159265//358979323846  /* pi */
#include <math.h>
#include <stdio.h>

class Player
{
public:
	Player();
	~Player();
	void update();
	void draw(sf::RenderWindow & window);
	sf::Vector2f getPos();

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_pos;
	float m_speed;
	float m_rotSpeed;
	void boundaryCheck();
	void movement();
};

#endif