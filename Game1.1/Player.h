#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> Bullets;
	float bulletSpeed = 0.7f;

	sf::RectangleShape collisionBox;

	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	void Initialize(); 
	void Load(); 

	void Update(Enemy& skeleton);
	void Draw(sf::RenderWindow& window);
};