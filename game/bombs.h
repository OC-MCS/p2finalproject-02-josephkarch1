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
	Sprite bombSprite;
	FloatRect bombBounds = bombSprite.getGlobalBounds();

public:

	bombs(int x, int y, textureManager* ptr)
	{
		bombSprite.setTexture(ptr->getBombTexture());
		bombSprite.setPosition(x, y);
	}

	Sprite& getSprite()
	{
		return bombSprite;
	}
};
