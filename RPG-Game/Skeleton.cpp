#include "Skeleton.h"

Skeleton::Skeleton() : 
	m_sprite(m_texture), 
	m_health{ 100 }, 
	m_healthText{m_healthFont}
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::initialize()
{
	m_size = { 64, 64 };

	m_outline.setFillColor(sf::Color::Transparent);
	m_outline.setOutlineColor(sf::Color::Yellow);
	m_outline.setOutlineThickness(1);
	m_outline.setPosition({ 0, 0 });
}

void Skeleton::load()
{

	if (m_healthFont.openFromFile("assets/fonts/arial.ttf"))
	{	  
		m_healthText.setFont(m_healthFont);
		m_healthText.setString(std::to_string(m_health));
		std::cout << "health font loaded successfully" << std::endl;
	}
	else
		std::cout << "failed loading health font" << std::endl;

	if (m_texture.loadFromFile("assets/skeleton/textures/spritesheet.png"))
	{
		std::cout << "skeleton texture loaded" << std::endl;
		m_sprite.setTexture(m_texture);
	}
	else
		std::cout << "skeleton texture failed to load" << std::endl;

	int XIndex = 0;
	int YIndex = 2;
	m_sprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
	m_sprite.setPosition({ 400, 600 });


	m_outline.setSize({ m_size.x * m_sprite.getScale().x, m_size.y * m_sprite.getScale().y });
	m_outline.setPosition(m_sprite.getPosition());
	m_healthText.setPosition(m_sprite.getPosition());
}

void Skeleton::update(double deltaTime)
{
	if (m_health > 0)
	{
	}
}

void Skeleton::draw(sf::RenderWindow& window)
{
	if (m_health > 0)
	{
		window.draw(m_sprite);
		window.draw(m_outline);
		window.draw(m_healthText);
	}
}

void Skeleton::setHealth(int health)
{
	m_health = health;
	m_healthText.setString(std::to_string(m_health));
}
