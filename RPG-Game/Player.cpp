#include "Player.h"


Player::Player() : 
	m_sprite(m_texture), 
	m_moveSpeed{ 0 }, 
	m_bulletFireRate{ 500.f }
{
}

Player::~Player()
{
}

void Player::initialize()
{
	m_size = { 64, 64 };
	m_moveSpeed = 2.0f;

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

void Player::update(Skeleton& skeleton, float deltaTime, sf::Vector2i& mousePosition)
{
	sf::Vector2f position = m_sprite.getPosition();

	m_outline.setPosition(m_sprite.getPosition());

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




	m_bulletFireRateTimer += deltaTime;

	// shoot with left mouse button
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && 
		m_bulletFireRateTimer >= m_bulletFireRate) {
		m_bullets.push_back(Bullet());
		m_bullets[m_bullets.size() - 1].initialize(m_sprite.getPosition(), sf::Vector2f(mousePosition));
		
		m_bulletFireRateTimer = 0;
	}

	for (size_t i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i].update(deltaTime);

		// if bullet collides with enemy, delete bullet
		if (skeleton.getHealth() > 0 && Math::didRectsCollide(m_bullets[i].getGlobalBounds(), skeleton.m_sprite.getGlobalBounds()))
		{
			m_bullets.erase(m_bullets.begin() + i);

			skeleton.setHealth(skeleton.getHealth() - 10);
			std::cout << "Skeleton health: " << skeleton.getHealth() << std::endl;
		}
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
		bullet.draw(window);
	}
}
