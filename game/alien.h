#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "gameUI.h"
#include "ship.h"


class alien
{
private:
	Texture alienTexture;
	Sprite alienSprite;


public:

	alien()
	{
		if (!alienTexture.loadFromFile("enemy.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		alienSprite.setTexture(alienTexture);
	};

	alien(int x2, int y2)
	{
		if (!alienTexture.loadFromFile("enemy.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}

		alienSprite.setTexture(alienTexture);
		alienSprite.setPosition(x2, y2);
	};

	Sprite& getSprite()
	{
		return alienSprite;
	}

};



