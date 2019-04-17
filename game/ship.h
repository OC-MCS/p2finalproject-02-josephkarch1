#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "textureManager.h"


class ship
{
private:
	Sprite ship1;
	FloatRect shipBounds = ship1.getGlobalBounds();
	float shipX = 400;
	float shipY= 550;

public:

	ship(textureManager* ptr)
	{		
		ship1.setPosition(shipX, shipY);
		ship1.setTexture(ptr->getShipTexture());
	}

	Sprite& getSprite()
	{
		return ship1;
	}

	void moveShip()
	{
		const float DISTANCE = 5.0f;

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			ship1.move(-DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			ship1.move(DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			ship1.move(0, -DISTANCE);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			ship1.move(0, DISTANCE);
		}

	}

	void checkBounds(RenderWindow& win)
	{
		int fixError = 20;
		// right x bonundary
		if (ship1.getPosition().x >= win.getSize().x - fixError)
		{
			ship1.setPosition(win.getSize().x - fixError, ship1.getPosition().y);

		}

		// bottom y boundary
		if (ship1.getPosition().y >= win.getSize().y - fixError)
		{
			ship1.setPosition(ship1.getPosition().x, win.getSize().y - fixError);
		}

		// left x boundary
		if (ship1.getPosition().x <= 0)
		{
			ship1.setPosition(0, ship1.getPosition().y);

		}

		// top y boundary
		if (ship1.getPosition().y <= 400)
		{
			ship1.setPosition(ship1.getPosition().x, 400);
		}
	}

	void draw(RenderWindow& win)
	{
		
		win.draw(ship1);
	}
};
