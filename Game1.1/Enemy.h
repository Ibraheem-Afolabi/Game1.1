#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture skeletonTexture;
	
public:
	sf::Sprite skeletonSprite;

public:
	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
};

