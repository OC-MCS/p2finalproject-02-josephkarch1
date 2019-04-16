#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "alien.h"
#include "gameUI.h"
#include "ship.h"

class alienArmy
{
private:
	vector<alien*> alienHolder;
	int alienExists[10] = { 1,1,1,1,1,1,1,1,1,1 };
	bool alienArmyRight = true;
	bool alienArmyLeft = false;
	bool twiceAlienArmyRight = false;
	int counter = 0;

public:

	alienArmy()
	{
		int startingX = -20;
		int startingY = 100;
		for (int x = 1; x < 11; x++)
		{
			alien* tempAlien;

			tempAlien = new alien(startingX + (x * 60), startingY);
			alienHolder.push_back(tempAlien);
		}


	}

	void draw(RenderWindow& win)
	{
		for (int y = 0; y < 10; y++)
		{
			if (alienExists[y] == 1)
			{
				win.draw(alienHolder[y]->getSprite());
			}

		}
	}

	void moveAlienArmy(RenderWindow& win)
	{
		Vector2f pos;
		if (alienArmyRight)
		{
			for (int y = 0; y < 10; y++)
			{
				pos = alienHolder[y]->getSprite().getPosition();
				pos.x += 5.0f;
				alienHolder[y]->getSprite().setPosition(pos);
			}
			
		}

		if (alienHolder[9]->getSprite().getPosition().x >= win.getSize().x - 35)
		{
			alienArmyRight = false;
			alienArmyLeft = true;
			counter++;

			if (counter == 4)
			{
				twiceAlienArmyRight = true;
			}
		}

		if (alienArmyLeft)
		{
			for (int y = 0; y < 10; y++)
			{
				alienHolder[y]->getSprite().setPosition(alienHolder[y]->getSprite().getPosition().x - 5, alienHolder[y]->getSprite().getPosition().y);
			}
		}

		if (alienHolder[0]->getSprite().getPosition().x <= 0)
		{
			alienArmyLeft = false;
			alienArmyRight = true;
		}

		if (twiceAlienArmyRight)
		{
			for (int y = 0; y < 10; y++)
			{
				alienHolder[y]->getSprite().setPosition(alienHolder[y]->getSprite().getPosition().x, alienHolder[y]->getSprite().getPosition().y + 100);
			}

			twiceAlienArmyRight = false;
			counter = 0;
		}
	}
};


