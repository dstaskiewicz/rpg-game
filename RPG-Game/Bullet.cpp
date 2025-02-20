#include "Bullet.h"

Bullet::Bullet() : 
	m_speed{ 1 },
	m_damage{ 30 }
{
}

Bullet::~Bullet()
{
}

void Bullet::initialize(const sf::Vector2f& position, const sf::Vector2f& target)
{
	m_rectangleShape.setSize(sf::Vector2f({ 2, 2 }));
	m_rectangleShape.setPosition(position);
	m_direction = Math::normalizeVector(target - position);
}

void Bullet::update(float deltaTime)
{
	m_rectangleShape.setPosition(m_rectangleShape.getPosition() + m_direction * m_speed * deltaTime);
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangleShape);
}
