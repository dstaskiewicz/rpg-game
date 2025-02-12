#include "Player.h"


Player::Player() : m_sprite(m_texture)
{
}

void Player::initialize()
{
}

void Player::load()
{
	if (m_texture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "Player texture loaded!" << std::endl;
		m_sprite.setTexture(m_texture);

		int XIndex = 0;
		int YIndex = 0;

		m_sprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));
		m_sprite.scale({ 3, 3 });
		m_sprite.setPosition({ 0, 0 });
	}
	else
	{
		std::cout << "Player texture failed to load!" << std::endl;
	}
}

void Player::update(Skeleton& skeleton)
{
	sf::Vector2f position = m_sprite.getPosition();

	// move up with W
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		m_sprite.setPosition(position + sf::Vector2f(0, -0.1 * m_moveSpeed));

	// move down with S
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		m_sprite.setPosition(position + sf::Vector2f(0, 0.1 * m_moveSpeed));

	// move left with A
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_sprite.setPosition(position + sf::Vector2f(-0.1 * m_moveSpeed, 0));

	// move right with D
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_sprite.setPosition(position + sf::Vector2f(0.1 * m_moveSpeed, 0));

	// shoot with left mouse button
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		bullets.push_back(sf::RectangleShape({ 2, 2 }));
		bullets[bullets.size() - 1].setPosition(m_sprite.getPosition());


	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bulletDirection = Math::normalizeVector(
			skeleton.m_sprite.getPosition() - bullets[i].getPosition());
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		if (bullets[i].getPosition() == skeleton.m_sprite.getPosition())
			bullets.erase(bullets.begin() + i);

	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	for (auto& bullet : bullets)
	{
		window.draw(bullet);
	}
}
