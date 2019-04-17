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
	Sprite alienSprite;
	FloatRect alienBounds = alienSprite.getGlobalBounds();

public:

	alien(textureManager* ptr)
	{
		alienSprite.setTexture(ptr->getEnemyTexture());
	};

	alien(int x2, int y2, textureManager* ptr)
	{
		alienSprite.setTexture(ptr->getEnemyTexture());
		alienSprite.setPosition(x2, y2);
	};

	Sprite& getSprite()
	{
		return alienSprite;
	}

};



