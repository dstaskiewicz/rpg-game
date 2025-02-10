#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// -------------------------------------------- INITIALIZE ----------------------------------------------------
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "RPG Game", sf::State::Windowed, settings);
	// -------------------------------------------- INITIALIZE ----------------------------------------------------
	// -------------------------------------------- LOAD ----------------------------------------------------
	sf::Texture playerTexture;
	if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
	{

		std::cout << "Player images loaded" << std::endl;
	}
	else
	{
		std::cout << "Player image failed to load" << std::endl;
	}

	int XIndex = 0;
	int YIndex = 0;
	sf::Sprite playerSprite(playerTexture);
	playerSprite.setTextureRect(sf::IntRect({ XIndex * 64, YIndex * 64 }, { 64, 64 }));

	// -------------------------------------------- LOAD ----------------------------------------------------
	while (window.isOpen())
	{

		// -------------------------------------------- UPDATE ----------------------------------------------------
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			

		}

		sf::Vector2f position = playerSprite.getPosition();

		// move up with W
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
			playerSprite.setPosition(position + sf::Vector2f(0, -0.1));

		// move down with S
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
			playerSprite.setPosition(position + sf::Vector2f(0, 0.1));

		// move left with A
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
			playerSprite.setPosition(position + sf::Vector2f(-0.1, 0));
		
		// move right with D
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			playerSprite.setPosition(position + sf::Vector2f(0.1, 0));

		// close with Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();
		
		// -------------------------------------------- UPDATE ----------------------------------------------------

		//
	// -------------------------------------------- DRAW ----------------------------------------------------
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
		// -------------------------------------------- DRAW ----------------------------------------------------
	}
}