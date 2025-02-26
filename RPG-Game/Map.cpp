#include "Map.h"

Map::Map() :
	//m_sprites{ 10, sf::Sprite(m_tilesheetTexture) },
	m_tileWidth{ 16 },
	m_tileHeight{ 16 },
	m_totalTilesX{ 0 },
	m_totalTilesY{ 0 },
	m_totalTiles{ 0 },
	m_tiles{ nullptr }
{
	for (int i = 0; i < 6; i++)
	{
		m_mapSprites[i] = new sf::Sprite(m_tilesheetTexture);
	}
}

Map::~Map()
{
	delete[] m_tiles;
	for (int i = 0; i < 6; i++)
	{
		delete m_mapSprites[i];
	}
}

void Map::initialize()
{
}

void Map::load()
{
	if (m_tilesheetTexture.loadFromFile("assets/world/prison/tilesheet.png"))
	{
		std::cout << "World prison tilesheet loaded" << std::endl;
		m_totalTilesX = m_tilesheetTexture.getSize().x / m_tileWidth;
		m_totalTilesY = m_tilesheetTexture.getSize().y / m_tileHeight;

		m_totalTiles = m_totalTilesX * m_totalTilesY;
		m_tiles = new Tile[m_totalTiles];

		for (int i = 0; i < m_totalTiles; i++)
		{
			int x = i % m_totalTilesX;
			int y = i / m_totalTilesX;

			m_tiles[i].id = i;
			m_tiles[i].m_position = { x * m_tileWidth, y * m_tileHeight };
		}
		
	}
	else
		std::cout << "World prison tilesheet failed to load" << std::endl;

	for (size_t y = 0; y < 2; y++)
	{
		for (size_t x = 0; x < 3; x++) 
		{
			int i = x + y * 3;
			m_mapSprites[i]->setTexture(m_tilesheetTexture);
			m_mapSprites[i]->setTextureRect(sf::IntRect(
				{ m_tiles[m_mapIDs[i]].m_position.x, m_tiles[m_mapIDs[i]].m_position.y },
				{ m_tileWidth, m_tileHeight }));
			m_mapSprites[i]->setPosition({ float(x * m_tileWidth * 5), float(y * m_tileHeight * 5) });
			m_mapSprites[i]->setScale({ 5, 5 });
		}
	}

}

void Map::update(float deltaTime)
{
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 6; i++)
	{
		window.draw(*m_mapSprites[i]);
	}
}
