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
	sf::Texture player1texture, enemy1texture;
	sf::Sprite player1sprite, enemy1sprite;

	//x and y axis, Width and Height (They're integers)
	int Xindex = 0, Yindex = 0;

	if (player1texture.loadFromFile("Assets/Player/Textures/spritesheet2.png")) {
		std::cout << "Player1 loaded!\n";
		player1sprite.setTexture(player1texture);
		//player1sprite.scale(1, 4)

		player1sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
	}
	if (enemy1texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
		std::cout << "Enemy1 Loaded!\n";
		enemy1sprite.setTexture(enemy1texture);

		enemy1sprite.setPosition(200, 0);
		enemy1sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
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
		sf::Vector2f oldPosition1 = enemy1sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	
			player1sprite.setPosition(oldPosition + sf::Vector2f(0, -1));
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			player1sprite.setPosition(oldPosition + sf::Vector2f(0, 1)); 
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
			player1sprite.setPosition(oldPosition + sf::Vector2f(1, 0));
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
			player1sprite.setPosition(oldPosition + sf::Vector2f(-1, 0));
		
		//Movement For Enemy Sprite
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			enemy1sprite.setPosition(oldPosition1 + sf::Vector2f(0, -1));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			enemy1sprite.setPosition(oldPosition1 + sf::Vector2f(-1, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			enemy1sprite.setPosition(oldPosition1 + sf::Vector2f(1, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			enemy1sprite.setPosition(oldPosition1 + sf::Vector2f(0, 1));
		//------------ UPDATE -------------

			//------------ DRAW -------------
			window.clear(sf::Color::Black);

			window.draw(player1sprite);
			window.draw(enemy1sprite);

			window.display();
			//------------ DRAW -------------

		





	}

	return 0;
}