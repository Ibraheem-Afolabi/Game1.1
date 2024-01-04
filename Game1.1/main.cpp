#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

int main() {

	//--------------- INITIALIZE ----------
	//Contex Settings...
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode(800, 600), "First Game", sf::Style::Default, settings);
	//--------------- INITIALIZE ----------

	Player player;
	player.Initialize();
	player.Load();

	Enemy skeleton;
	skeleton.Initialize();
	skeleton.Load();


	//Main game loop
	while (window.isOpen()) {

		//------------ UPDATE -------------
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		skeleton.Update();
		player.Update(skeleton);
		//------------ UPDATE -------------

		//------------ DRAW -------------
		window.clear(sf::Color::Black);

		player.Draw(window);
		skeleton.Draw(window);

		window.display();
		//------------ DRAW -------------	
	}
	return 0;
}