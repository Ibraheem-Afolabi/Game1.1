#include "Math.h"


sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
	float m = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

//rect1.Right > rect2.Left &&
//rect1.Right < rect2.left &&
//
//rect2.bottom < rect1.top &&
//rect2.top > rect1.bottom

bool Math::checkRectCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (rect1.left + rect1.width > rect2.left && rect2.left + rect2.width &&
		rect2.top + rect2.height > rect1.top &&
		rect1.top + rect1.height > rect2.top)
		return true;


	return false;
}
