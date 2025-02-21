#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
public:
	Map();
	~Map();

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);


private:
	sf::Texture m_tilesheetTexture;
	std::vector<sf::Sprite> m_sprites;

	const int m_tileWidth;
	const int m_tileHeight;

	int m_totalTilesX;
	int m_totalTilesY;
};

