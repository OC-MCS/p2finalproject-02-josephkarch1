#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "gameUI.h"
#include "ship.h"
#include "textureManager.h"


class alien
{
private:

	Sprite returnSprite;											//the base sprite for the aliens
	FloatRect alienBounds = returnSprite.getGlobalBounds();			// holds the boundary coordinates of the alien sprites
	textureManager* pointerHolder;									// poiter to hold address to texture manager
	int xValue;														// holds the x default starting values of the alien. later reference point for loops
	int yValue;														// holds the y default starting values of the alien. later reference point for loops

public:

	alien(textureManager* ptr)
	{
		pointerHolder = ptr;
	};

	alien(int x2, int y2, textureManager* ptr)
	{
		// set the default x and y coordinate position for the alien
		returnSprite.setPosition(x2, y2);
		returnSprite.setPosition(x2, y2);
		pointerHolder = ptr;
	};

//================================================================================
// getSprite: getter for the address to the alien sprite
// parameters: N/A
// return type: alien sprite address
//================================================================================
	Sprite& getSprite()
	{
		return returnSprite;
	}

//================================================================================
// setSpriteA: sets the texture of the sprte for level 1
// parameters: N/A
// return type: N/A
//================================================================================
	void setSpriteA()
	{
		returnSprite.setTexture(pointerHolder->getEnemyTexture());
	}

//================================================================================
// setSpriteB: sets the texture of the sprte for level 2
// parameters: N/A
// return type: N/A
//================================================================================
	void setSpriteB()
	{
		returnSprite.setTexture(pointerHolder->getEnemyTexture2());
	}

};



