#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "Player.h"
#include "Skeleton.h"



int main()
{
	// ------------------------------- INITIALIZE -----------------------------------------
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "RPG Game", sf::State::Windowed, settings);

	Player player;
	player.initialize();
	Skeleton skeleton;
	skeleton.initialize();
	// ---------------------------------- INITIALIZE --------------------------------------
	// 
	// -------------------------------------- LOAD ----------------------------------------
	
	player.load();
	skeleton.load();



	// ----------------------------------- LOAD --------------------------------
	while (window.isOpen())
	{

		// ----------------------------------- UPDATE -------------------------------
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			

		}

		skeleton.update();
		player.update(skeleton);

		// close with Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		

		// ---------------------------------- UPDATE --------------------------------------
		//
		// ----------------------------------- DRAW -------------------------------------------
		window.clear(sf::Color::Black);

		

		skeleton.draw(window);
		player.draw(window);
		window.display();
		// ------------------------------------- DRAW -------------------------------------
	}
}