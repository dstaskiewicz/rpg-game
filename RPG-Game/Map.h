#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tile.h"

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
	Tile* m_tiles;
	int m_mapIDs[6] = {
		1, 1, 1, 
		24, 26, 29 
	};
	sf::Sprite* m_mapSprites[6];

	const int m_tileWidth;
	const int m_tileHeight;

	int m_totalTilesX;
	int m_totalTilesY;
	int m_totalTiles;
};

