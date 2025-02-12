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
	void update(Skeleton& skeleton);
	void draw(sf::RenderWindow& window);

	
	sf::Sprite m_sprite;

private:

	sf::Texture m_texture;
	std::vector<sf::RectangleShape> bullets;
	float m_moveSpeed{1.f};


	float bulletSpeed = 0.5f;
	sf::Vector2f bulletDirection;
};

