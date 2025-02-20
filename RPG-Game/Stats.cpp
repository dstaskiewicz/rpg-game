#include "Stats.h"

Stats::Stats() : m_framerateText(m_framerateFont), m_framerateTimer{0.0f}
{
}

Stats::~Stats()
{
}

void Stats::initialize()
{
}

void Stats::load()
{
	if (m_framerateFont.openFromFile("assets/fonts/arial.ttf"))
	{
		m_framerateText.setFont(m_framerateFont);
		std::cout << "font loaded successfully" << std::endl;
	}
	else
		std::cout << "failed loading font" << std::endl;
}

void Stats::update(float deltaTime)
{
	m_framerateTimer += deltaTime;
	if (m_framerateTimer >= 250000) 
	{

		m_framerateText.setString("FPS: " + std::to_string((int)(1000000 / deltaTime)));
		m_framerateTimer = 0.0f;
	}
}

void Stats::draw(sf::RenderWindow& window)
{
	window.draw(m_framerateText);
}
