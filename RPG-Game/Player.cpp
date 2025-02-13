#include "Player.h"


Player::Player() : m_sprite(m_texture)
{
}

void Player::initialize()
{
	m_size = { 64, 64 };
	m_moveSpeed = 2.0f;
	m_bulletSpeed = 0.5f;

	m_outline.setFillColor(sf::Color::Transparent);
	m_outline.setOutlineColor(sf::Color::White);
	m_outline.setOutlineThickness(1);
}

void Player::load()
{
	if (m_texture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "Player texture loaded!" << std::endl;
		m_sprite.setTexture(m_texture);

		int XIndex = 0;
		int YIndex = 0;

		m_sprite.setTextureRect(sf::IntRect({ XIndex * m_size.x, YIndex * m_size.y }, { m_size.x, m_size.y }));
		m_sprite.scale(m_sprite.getScale());
		m_sprite.setPosition({ 0, 0 });

		m_outline.setSize({ m_size.x * m_sprite.getScale().x, m_size.y * m_sprite.getScale().y });
		m_outline.setPosition(m_sprite.getPosition());
	}
	else
	{
		std::cout << "Player texture failed to load!" << std::endl;
	}
}

void Player::update(Skeleton& skeleton, float deltaTime)
{
	sf::Vector2f position = m_sprite.getPosition();


	// move up with W
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		m_sprite.setPosition(position + sf::Vector2f(0, -1 * m_moveSpeed * deltaTime));

	// move down with S
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		m_sprite.setPosition(position + sf::Vector2f(0, 1 * m_moveSpeed * deltaTime));

	// move left with A
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_sprite.setPosition(position + sf::Vector2f(-1 * m_moveSpeed * deltaTime, 0));

	// move right with D
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_sprite.setPosition(position + sf::Vector2f(1 * m_moveSpeed * deltaTime, 0));

	// shoot with left mouse button
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		m_bullets.push_back(sf::RectangleShape({ 2, 2 }));
		m_bullets[m_bullets.size() - 1].setPosition(m_sprite.getPosition());


	}

	m_outline.setPosition(m_sprite.getPosition());

	for (size_t i = 0; i < m_bullets.size(); i++)
	{
		m_bulletDirection = Math::normalizeVector(
			skeleton.m_sprite.getPosition() - m_bullets[i].getPosition());
		m_bullets[i].setPosition(m_bullets[i].getPosition() + m_bulletDirection * m_bulletSpeed * deltaTime);
		//if (m_bullets[i].getPosition() == skeleton.m_sprite.getPosition())
		if (Math::didRectsCollide(m_bullets[i].getGlobalBounds(), 
				skeleton.m_sprite.getGlobalBounds()))
			m_bullets.erase(m_bullets.begin() + i);

	}

	if (Math::didRectsCollide(m_sprite.getGlobalBounds(), skeleton.m_sprite.getGlobalBounds()))
	{
		std::cout << "Collision" << std::endl;
	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_outline);
	for (auto& bullet : m_bullets)
	{
		window.draw(bullet);
	}
}
