#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	//--------------- INITIALIZE ----------

	//Contex Settings...
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;


	sf::RenderWindow window(sf::VideoMode(800, 600), "First Game", sf::Style::Default, settings);

	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(100, 100));
	shape.setOutlineThickness(10.9f);
	shape.setOutlineColor(sf::Color::Green);

	sf::RectangleShape rect(sf::Vector2f(150.f, 50.f));
	rect.setPosition(sf::Vector2f(250, 150));
	rect.setFillColor(sf::Color::Red);
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setRotation(45);

	sf::CircleShape hexagon(60.f, 6);
	hexagon.setPosition(sf::Vector2f(300, 300));

	sf::CircleShape oct(50.f, 8);
	oct.setPosition(100, 400);
	oct.setFillColor(sf::Color::Magenta);

	sf::RectangleShape diamond(sf::Vector2f(50.f, 50.f));
	diamond.setPosition(300, 500);
	diamond.setFillColor(sf::Color::Cyan);
	diamond.setOrigin(diamond.getSize() / 2.f);
	diamond.setRotation(50);

	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(10.f, 10.f)),
		sf::Vertex(sf::Vector2f(250.f, 250.f))
	};


	//--------------- INITIALIZE ----------

	//Main game loop
	while (window.isOpen()) {

		//------------ UPDATE -------------
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			//------------ UPDATE -------------

			//------------ DRAW -------------
			window.clear(sf::Color::Black);

			window.draw(rect);
			window.draw(shape);
			window.draw(hexagon);
			window.draw(oct);
			window.draw(diamond);
			window.draw(line, 2, sf::Lines);

			window.display();
			//------------ DRAW -------------

		}





	}

	return 0;
}