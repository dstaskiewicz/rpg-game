#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Skeleton
{
public:
	Skeleton();
	~Skeleton();

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	sf::Sprite m_sprite;

	void setHealth(int health);
	inline const int& getHealth() const { return m_health; }



private:
	sf::Texture m_texture;
	sf::RectangleShape m_outline;
	sf::Vector2i m_size;

	int m_health;
	sf::Font m_healthFont;
	sf::Text m_healthText;
};

