#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "projectiles.h"
#include "textureManager.h"

class bombs
{
private:
	Sprite bombSprite;										// sprite for the bombs
	FloatRect bombBounds = bombSprite.getGlobalBounds();	// FloatRect which holds the boundary coordinates of the bomb sprite

public:

	bombs(int x, int y, textureManager* ptr)
	{
		// set bomb texture and position
		bombSprite.setTexture(ptr->getBombTexture());
		bombSprite.setPosition(x, y);
	}

//================================================================================
// getSprite: getter function which returns the address to the bomb sprite
// parameters: N/A
// return type: sprite address
//================================================================================
	Sprite& getSprite()
	{
		return bombSprite;
	}
};
