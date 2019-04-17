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
	Sprite missileSprite;
	FloatRect missileBounds = missileSprite.getGlobalBounds();

public:

	missiles(int x, int y, textureManager* ptr)
	{
		missileSprite.setTexture(ptr->getMissileTexture());
		missileSprite.setPosition(x, y);
	}

	Sprite& getSprite()
	{
		return missileSprite;
	}
};
