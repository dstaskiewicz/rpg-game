#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Skeleton
{
public:
	Skeleton();

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	sf::Sprite m_sprite;

private:
	sf::Texture m_texture;
	sf::RectangleShape m_outline;
	sf::Vector2i m_size;
};

