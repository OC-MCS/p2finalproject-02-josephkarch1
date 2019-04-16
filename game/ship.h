#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


class ship
{
private:
	Texture shipTexture;
	Sprite ship1;
	float shipX = 400;
	float shipY= 550;

public:

	ship()
	{		
		ship1.setPosition(shipX, shipY);
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);

		}

		ship1.setTexture(shipTexture);
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
