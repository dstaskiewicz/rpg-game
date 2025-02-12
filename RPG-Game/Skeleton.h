#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Skeleton
{
public:
	Skeleton();

	void initialize();
	void load();
	void update();
	void draw(sf::RenderWindow& window);

	sf::Sprite m_sprite;

private:
	sf::Texture m_texture;
};

