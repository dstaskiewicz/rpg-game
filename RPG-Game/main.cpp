#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;
	return normalizedVector;

}

int main()
{
	// ------------------------------- INITIALIZE -----------------------------------------
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "RPG Game", sf::State::Windowed, settings);
	// ---------------------------------- INITIALIZE --------------------------------------
	// -------------------------------------- LOAD ----------------------------------------
	


	// Player
	sf::Texture playerTexture;
	if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
		std::cout << "Player texture loaded" << std::endl;
	else
		std::cout << "Player texture failed to load" << std::endl;

	int playerXIndex = 0;
	int playerYIndex = 0;
	sf::Sprite playerSprite(playerTexture);
	playerSprite.setTextureRect(sf::IntRect({ playerXIndex * 64, playerYIndex * 64 }, { 64, 64 }));

	float playerMovementSpeed = 5.f;


	// skeleton
	sf::Texture skeletonTexture; 
	if (skeletonTexture.loadFromFile("assets/skeleton/textures/spritesheet.png"))
		std::cout << "skeleton texture loaded" << std::endl;
	else
		std::cout << "skeleton texture failed to load" << std::endl;

	int skeletonXIndex = 0;
	int skeletonYIndex = 2;
	sf::Sprite skeletonSprite(skeletonTexture);
	skeletonSprite.setTextureRect(sf::IntRect({ skeletonXIndex * 64, skeletonYIndex * 64 }, 
		{ 64, 64 }));
	skeletonSprite.setPosition({ 400, 600 });


	// Bullets
	//sf::RectangleShape bullet({ 50, 25 });
	//bullet.setFillColor(sf::Color::Yellow);
	//bullet.setPosition(playerSprite.getPosition());
	//sf::Vector2f bulletDirection = NormalizeVector(skeletonSprite.getPosition() - bullet.getPosition());

	float bulletSpeed = 0.5f;
	std::vector<sf::RectangleShape> bullets;
	sf::Vector2f bulletDirection;

	// ----------------------------------- LOAD --------------------------------
	while (window.isOpen())
	{

		// ----------------------------------- UPDATE -------------------------------
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			

		}


		sf::Vector2f position = playerSprite.getPosition();

		// move up with W
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
			playerSprite.setPosition(position + sf::Vector2f(0, -0.1 * playerMovementSpeed));

		// move down with S
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
			playerSprite.setPosition(position + sf::Vector2f(0, 0.1 * playerMovementSpeed));

		// move left with A
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
			playerSprite.setPosition(position + sf::Vector2f(-0.1 * playerMovementSpeed, 0));
		
		// move right with D
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			playerSprite.setPosition(position + sf::Vector2f(0.1 * playerMovementSpeed, 0));

		// close with Escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		// shoot with letf mouse button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			bullets.push_back(sf::RectangleShape({ 20, 20 }));
			bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());
			

		}

		for (auto &bullet : bullets)
		{
			bulletDirection = NormalizeVector(
				skeletonSprite.getPosition() - bullet.getPosition());
			bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);
		}
		
		// ---------------------------------- UPDATE --------------------------------------

		//
		// ----------------------------------- DRAW -------------------------------------------
		window.clear(sf::Color::Black);
		//window.draw(bullet);
		for (auto &bullet : bullets)
		{
			window.draw(bullet);
		}
		window.draw(skeletonSprite);
		window.draw(playerSprite);
		window.display();
		// ------------------------------------- DRAW -------------------------------------
	}
}