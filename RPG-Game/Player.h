#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Skeleton.h"
#include "Math.h"

class Player
{
public:
	Player();

	void initialize();
	void load();
	void update(Skeleton& skeleton, float deltaTime);
	void draw(sf::RenderWindow& window);

	
	sf::Sprite m_sprite;

private:

	sf::Texture m_texture;
	sf::RectangleShape m_outline;
	float m_moveSpeed;
	sf::Vector2i m_size;

	std::vector<sf::RectangleShape> m_bullets;
	float m_bulletSpeed;
	sf::Vector2f m_bulletDirection;
};

