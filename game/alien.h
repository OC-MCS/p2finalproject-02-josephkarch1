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
	Sprite alienSprite2;
	Sprite returnSprite;
	FloatRect alienBounds = alienSprite.getGlobalBounds();

public:

	alien(textureManager* ptr)
	{
		alienSprite.setTexture(ptr->getEnemyTexture());
		alienSprite2.setTexture(ptr->getEnemyTexture2());
	};

	alien(int x2, int y2, textureManager* ptr)
	{
		alienSprite.setTexture(ptr->getEnemyTexture());
		alienSprite2.setTexture(ptr->getEnemyTexture2());
		alienSprite.setPosition(x2, y2);
	};

	Sprite& getSprite()
	{
		return alienSprite;
	}

	Sprite& getSprite2()
	{
		return alienSprite2;
	}

};



