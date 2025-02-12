#include "Skeleton.h"

Skeleton::Skeleton() : m_sprite(m_texture) {}

void Skeleton::initialize()
{
}

void Skeleton::load()
{
	if (m_texture.loadFromFile("assets/skeleton/textures/spritesheet.png"))
	{
		std::cout << "skeleton texture loaded" << std::endl;
		m_sprite.setTexture(m_texture);
	}
	else
		std::cout << "skeleton texture failed to load" << std::endl;

	int XIndex = 0;
	int YIndex = 2;
	m_sprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 },
		{ 64, 64 }));
	m_sprite.setPosition({ 400, 600 });
}

void Skeleton::update()
{
}

void Skeleton::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
