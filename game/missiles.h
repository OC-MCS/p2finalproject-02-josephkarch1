#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "projectiles.h"

class missiles
{
private:
	Sprite missileSprite;											 // sprite for the missiles
	FloatRect missileBounds = missileSprite.getGlobalBounds();		 // FloatRect which holds the boundary coordinates of the sprite

public:

	missiles(int x, int y, textureManager* ptr)
	{
		// set missile sprite's texture and position
		missileSprite.setTexture(ptr->getMissileTexture());
		missileSprite.setPosition(x, y);
	}


//================================================================================
// getSprite: getter function which returns the address to missile sprite
// parameters: N/A
// return type: sprite address
//================================================================================
	Sprite& getSprite()
	{
		return missileSprite;
	}
};
