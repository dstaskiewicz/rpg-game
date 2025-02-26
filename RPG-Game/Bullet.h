#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Math.h"

class Bullet
{
public:
	Bullet();
	~Bullet();


	void initialize(const sf::Vector2f& position, const sf::Vector2f& target);
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);

	inline const sf::FloatRect& getGlobalBounds() { return m_rectangleShape.getGlobalBounds(); }

private:
	sf::RectangleShape m_rectangleShape;

	sf::Vector2f m_direction;
	float m_speed;
	int m_damage;
};

