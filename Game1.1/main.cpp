#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	//--------------- INITIALIZE ----------

	//Contex Settings...
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode(800, 600), "First Game", sf::Style::Default, settings);

	//--------------- INITIALIZE ----------

	//--------------- LOAD ----------
	sf::Texture player1texture;
	sf::Sprite player1sprite;

	if (player1texture.loadFromFile("Assets/Player/Textures/spritesheet2.png")) {
		std::cout << "Player1 loaded!\n";
		player1sprite.setTexture(player1texture);
		//player1sprite.scale(1, 4);

		//x and y axis, Width and Height (They're integers)
		int Xindex = 0, Yindex = 0;

		player1sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
	}
	else {
		std::cout << "Player image failed to load!\n";
	}
	
	//--------------- LOAD ----------

	//Main game loop
	while (window.isOpen()) {

		//------------ UPDATE -------------

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}


		}
	
		sf::Vector2f oldPosition = player1sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	
			player1sprite.setPosition(oldPosition + sf::Vector2f(0, -1));
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			player1sprite.setPosition(oldPosition + sf::Vector2f(0, 1)); 
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
			player1sprite.setPosition(oldPosition + sf::Vector2f(1, 0));
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
			player1sprite.setPosition(oldPosition + sf::Vector2f(-1, 0));

		//------------ UPDATE -------------

			//------------ DRAW -------------
			window.clear(sf::Color::Black);

			window.draw(player1sprite);

			window.display();
			//------------ DRAW -------------

		





	}

	return 0;
}