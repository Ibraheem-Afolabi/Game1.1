#include <iostream>
#include "Enemy.h"

void Enemy::Initialize() {
	collisionBox.setFillColor(sf::Color::Transparent);
	collisionBox.setOutlineColor(sf::Color::Green);
	collisionBox.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
	collisionBox.setSize(sf::Vector2f(size.x, size.y));
}

void Enemy::Load() {
	if (skeletonTexture.loadFromFile("Assets/Enemy/Textures/spritesheet.png")) {
		std::cout << "Skeleton Loaded!\n";
		skeletonSprite.setTexture(skeletonTexture);

		int Xindex = 0, Yindex = 2;

		skeletonSprite.setPosition(200, 200);
		skeletonSprite.setTextureRect(sf::IntRect(Xindex * size.x, Yindex * size.y, size.x, size.y));
	}
}

void Enemy::Update()
{
	sf::Vector2f oldPosition1 = skeletonSprite.getPosition();


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(0, -1));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(-1, 0));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(1, 0));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		skeletonSprite.setPosition(oldPosition1 + sf::Vector2f(0, 1));

	collisionBox.setPosition(skeletonSprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(skeletonSprite);
	window.draw(collisionBox);
}

