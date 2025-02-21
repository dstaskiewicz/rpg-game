#include "Map.h"

Map::Map() :
	m_sprites{ 10, sf::Sprite(m_tilesheetTexture) },
	m_tileWidth{ 16 },
	m_tileHeight{ 16 },
	m_totalTilesX{ 0 },
	m_totalTilesY{ 0 }
{
}

Map::~Map()
{
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
		for (auto& sprite : m_sprites) {
			sprite.setTexture(m_tilesheetTexture);
		}
	}
	else
		std::cout << "World prison tilesheet failed to load" << std::endl;

	for (int i = 0; i < 10; i++)
	{

		m_sprites[i].setTextureRect(sf::IntRect({0 * m_tileWidth, i * m_tileHeight}, {m_tileWidth, m_tileHeight}));
		m_sprites[i].setPosition({ 100, float(4 * i * m_tileHeight + 100) });
		m_sprites[i].setScale({ 4, 4 });
	}

}

void Map::update(float deltaTime)
{
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 10; i++)
	{
		window.draw(m_sprites[i]);
	}
}
