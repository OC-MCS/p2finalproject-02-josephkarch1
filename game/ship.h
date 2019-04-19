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
	Sprite ship1;										// sprite for the ship
	FloatRect shipBounds = ship1.getGlobalBounds();		// FloatRect holds the boundary coordinates for the ship
	float shipX = 400;									// stores the ship x coordinate
	float shipY= 500;									// stores the ship y coordinates

public:

	ship(textureManager* ptr)
	{		
		ship1.setPosition(shipX, shipY);
		ship1.setTexture(ptr->getShipTexture());
	}

//================================================================================
// getSprite: returns the address to the ship's sprite
// parameters: N/A
// return type: Sprite&
//================================================================================
	Sprite& getSprite()
	{
		return ship1;
	}

//================================================================================
// resetShipToStart: resets the ship to its starting location
// parameters: N/A
// return type: Sprite&
//================================================================================
	void resetShipToStart()
	{
		ship1.setPosition(shipX, shipY);
	}

//================================================================================
// moveShip: moves the ship if the keyboard key is pressed
// parameters: N/A
// return type: Sprite&
//================================================================================
	void moveShip()
	{
		const float DISTANCE = 10.0f;

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

//================================================================================
// checkBounds: checks the position of the shp against the window dimensions of the UI
// it prevents the ship from going outside the boundaries of the UI
// parameters: RenderWindow& win
// return type: void
//================================================================================
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

//================================================================================
// draw: draws the ship
// parameters: RenderWindow& win
// return type: void
//================================================================================
	void draw(RenderWindow& win)
	{
		
		win.draw(ship1);
	}
};
