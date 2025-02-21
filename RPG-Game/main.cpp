#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "Map.h"
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


	sf::Clock clock;
	sf::Time deltaTime;

	sf::Vector2i mousePosition;
	float deltaTimeAsMs;
	

	Map map;
	Player player;
	Skeleton skeleton;
	Stats stats;

	map.initialize();
	player.initialize();
	skeleton.initialize();
	stats.initialize();


	// ---------------------------------- INITIALIZE --------------------------------------
	// 
	// ----------------------------------- LOAD ----------------------------------------
	
	map.load();
	player.load();
	skeleton.load();
	stats.load();

	// ----------------------------------- LOAD --------------------------------
	while (window.isOpen())
	{

		// ----------------------------------- UPDATE -------------------------------

		deltaTime = clock.restart();
		mousePosition = sf::Mouse::getPosition(window);
		deltaTimeAsMs = deltaTime.asMilliseconds();
		

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		// close with Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		map.update(deltaTimeAsMs);
		skeleton.update(deltaTimeAsMs);
		player.update(skeleton, deltaTimeAsMs, mousePosition);
		stats.update(deltaTime.asMicroseconds());



		// ---------------------------------- UPDATE --------------------------------------
		//
		// ----------------------------------- DRAW ---------------------------------------
		window.clear(sf::Color::Black);

		map.draw(window);
		skeleton.draw(window);
		player.draw(window);
		stats.draw(window);


		window.display();
		// ------------------------------------- DRAW -------------------------------------

	}
}