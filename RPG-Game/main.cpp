#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "Player.h"
#include "Skeleton.h"
#include "Stats.h"



int main()
{
	// ------------------------------- INITIALIZE -----------------------------------------

	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "RPG Game", sf::State::Windowed, settings);
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	


	Player player;
	player.initialize();

	Skeleton skeleton;
	skeleton.initialize();

	Stats stats;
	stats.initialize();

	sf::Clock clock;
	sf::Time deltaTime;



	// ---------------------------------- INITIALIZE --------------------------------------
	// 
	// -------------------------------------- LOAD ----------------------------------------
	
	player.load();
	skeleton.load();
	stats.load();

	

	// ----------------------------------- LOAD --------------------------------
	while (window.isOpen())
	{

		// ----------------------------------- UPDATE -------------------------------

		deltaTime = clock.restart();
		//std::cout << deltaTime.asMilliseconds() << std::endl;
		//std::cout << "FPS: " << 1000 / deltaTime.asMilliseconds() << std::endl;
		

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		float deltaTimeAsMs = deltaTime.asMilliseconds();
		skeleton.update(deltaTimeAsMs);
		player.update(skeleton, deltaTimeAsMs);
		stats.update(deltaTime.asMicroseconds());

		// close with Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		// ---------------------------------- UPDATE --------------------------------------
		//
		// ----------------------------------- DRAW ---------------------------------------
		window.clear(sf::Color::Black);

		skeleton.draw(window);
		player.draw(window);
		stats.draw(window);

		window.display();
		// ------------------------------------- DRAW -------------------------------------

	}
}