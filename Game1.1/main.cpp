#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>


sf::Vector2f NormalizeVector(sf::Vector2f vector) {
	float m = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main() {

	//--------------- INITIALIZE ----------

	//Contex Settings...
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	sf::RenderWindow window(sf::VideoMode(800, 600), "First Game", sf::Style::Default, settings);

	//--------------- INITIALIZE ----------



	//--------------- LOAD ----------

	sf::Texture player1texture, skeletonTexture;
	sf::Sprite player1sprite, skeletonSprite;

	//----------- Player -----------------------

	if (player1texture.loadFromFile("Assets/Player/Textures/spritesheet2.png")) {
		std::cout << "Player1 loaded!\n";
		player1sprite.setTexture(player1texture);
		player1sprite.setPosition(650, 500);
		//player1sprite.scale(1, 4)

		int Xindex = 0, Yindex = 2;

		player1sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
	}
	//----------- Player -----------------------

	std::vector<sf::RectangleShape> Bullets;
	float bulletSpeed = 0.7f;

	//----------- Enemy -----------------------

	if (skeletonTexture.loadFromFile("Assets/Enemy/Textures/spritesheet.png")) {
		std::cout << "Skeleton Loaded!\n";
		skeletonSprite.setTexture(skeletonTexture);

		int Xindex = 0, Yindex = 2;

		skeletonSprite.setPosition(200, 200);
		skeletonSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
	}
	//----------- Enemy -----------------------
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
		sf::Vector2f oldPosition1 = skeletonSprite.getPosition();
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
			skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(0, -1));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(-1, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(1, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(0, 1));
		//

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

			Bullets.push_back(sf::RectangleShape(sf::Vector2f(15, 6)));

			int i = Bullets.size() - 1;
			Bullets[i].setPosition(player1sprite.getPosition());


		}

		for (size_t i = 0; i < Bullets.size(); i++) {

			sf::Vector2f bulletDirection = skeletonSprite.getPosition() - Bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);

			Bullets[i].setPosition(Bullets[i].getPosition() + (bulletDirection * bulletSpeed));
		}
		
		
		//------------ UPDATE -------------

			//------------ DRAW -------------

			window.clear(sf::Color::Black);
			window.draw(skeletonSprite);
			window.draw(player1sprite);
			for (size_t i = 0; i < Bullets.size(); i++) {
				window.draw(Bullets[i]);
			}

			window.display();

			//------------ DRAW -------------



	}

	return 0;
}