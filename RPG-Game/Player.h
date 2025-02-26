#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Skeleton.h"
#include "Math.h"
#include "Bullet.h"

class Player
{
public:
	Player();
	~Player();

	void initialize();
	void load();
	void update(Skeleton& skeleton, double deltaTime, sf::Vector2i& mousePosition);
	void draw(sf::RenderWindow& window);

	

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::RectangleShape m_outline;
	float m_moveSpeed;
	sf::Vector2i m_size;

	std::vector<Bullet> m_bullets;
	float m_bulletFireRateTimer;
	float m_bulletFireRate;
	
};

