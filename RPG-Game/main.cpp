#include <SFML/Graphics.hpp>

int main()
{

	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "RPG Game", sf::State::Windowed, settings);
	sf::RectangleShape shape(sf::Vector2f(50.f, 50.f));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(500.f, 70.f));
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color::Green);
	// game loop
	while (window.isOpen())
	{
		// update
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

		}

		//draw
		window.clear(sf::Color::Black);

		window.draw(shape);

		window.display();
	}
}