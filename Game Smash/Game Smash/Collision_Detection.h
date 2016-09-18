#pragma once

class BoundingBox
{
public:
	sf::RectangleShape rect;
	float bottom, left, right, top;

	BoundingBox(sf::Vector2f position, sf::Vector2f size, sf::Color color)
	{
		rect.setFillColor(color);
		rect.setPosition(position);
		rect.setSize(size);
	}

	void update()
	{
		bottom = rect.getPosition().y + rect.getSize().y;
		left = rect.getPosition().x;
		right = rect.getPosition().x + rect.getSize().x;
		top = rect.getPosition().y;
	}

	bool Collision(BoundingBox C)
	{
		if (right < C.left || left > C.right || top > C.bottom || bottom < C.top)
			return false;
		else
			return true;
	}
};