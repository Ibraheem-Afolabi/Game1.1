#include <iostream>
#include "Player.h"
#include "Math.h"


void Player::Initialize() {
	collisionBox.setFillColor(sf::Color::Transparent);
	collisionBox.setOutlineColor(sf::Color::Red);
	collisionBox.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
	collisionBox.setSize(sf::Vector2f(size.x, size.y));
}

void Player::Load() {
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet2.png")) {

		std::cout << "Player1 loaded!\n";
		sprite.setTexture(texture);
		sprite.setPosition(650, 500);

		int Xindex = 0, Yindex = 2;

		sprite.setTextureRect(sf::IntRect(Xindex * size.x, Yindex * size.y, size.x, size.y));
	}
}

void Player::Update(Enemy& skeleton) {
	sf::Vector2f oldPosition = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(oldPosition + sf::Vector2f(0, -1));

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		sprite.setPosition(oldPosition + sf::Vector2f(0, 1));

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(oldPosition + sf::Vector2f(1, 0));

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.setPosition(oldPosition + sf::Vector2f(-1, 0));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

		Bullets.push_back(sf::RectangleShape(sf::Vector2f(15, 6)));

		int i = Bullets.size() - 1;
		Bullets[i].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < Bullets.size(); i++) {
		
		sf::Vector2f bulletDirection = skeleton.skeletonSprite.getPosition() - Bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);

		Bullets[i].setPosition(Bullets[i].getPosition() + (bulletDirection * bulletSpeed));
	}
	collisionBox.setPosition(sprite.getPosition());

	if (Math::checkRectCollision(sprite.getGlobalBounds(), skeleton.skeletonSprite.getGlobalBounds())) {
		std::cout << "Collision Detected!!!!!!!!!!1" << std::endl;
	}

}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(collisionBox);

	for (size_t i = 0; i < Bullets.size(); i++) {
		window.draw(Bullets[i]);
	}
}

