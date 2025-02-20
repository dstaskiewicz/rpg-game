#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Stats
{
public:
	Stats();
	~Stats();
	

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
private:

	sf::Font m_framerateFont;
	sf::Text m_framerateText;

	float m_framerateTimer;
};

