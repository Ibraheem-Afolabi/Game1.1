#include <iostream>
#include "Enemy.h"

void Enemy::Initialize() {
	
}

void Enemy::Load() {
	if (skeletonTexture.loadFromFile("Assets/Enemy/Textures/spritesheet.png")) {
		std::cout << "Skeleton Loaded!\n";
		skeletonSprite.setTexture(skeletonTexture);

		int Xindex = 0, Yindex = 2;

		skeletonSprite.setPosition(200, 200);
		skeletonSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
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
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(skeletonSprite);
}

