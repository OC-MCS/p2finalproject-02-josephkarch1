#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
#include <list>
using namespace sf;
#include "alien.h"
#include "gameUI.h"
#include "ship.h"
#include "textureManager.h"

class alienArmy
{
private:
	list<alien*> alienHolder2;
	bool alienArmyRight = true;
	bool alienArmyLeft = false;
	bool dropAlienArmy = false;
	int counter = 0;
	

public:

	alienArmy(textureManager* ptr)
	{
		int startingX = -20;
		int startingY = 100;

		for (int x = 1; x < 11; x++)
		{
			alien* tempAlien;

			tempAlien = new alien(startingX + (x * 60), startingY, ptr);
			alienHolder2.push_back(tempAlien);
		}
	}
	int getSize()
	{
		return alienHolder2.size();
	}

	void draw(RenderWindow& win)
	{
		list<alien*>::iterator iter;

		for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
		{
			win.draw((*iter)->getSprite());
		}
	}
	void deleteAlien(int index)
	{
		list<alien*>::iterator iter;

		iter = alienHolder2.begin();
		advance(iter, index);
		iter = alienHolder2.erase(iter);
	}

	Sprite& getSprite(int index)
	{
		list<alien*>::iterator iter;

		iter = alienHolder2.begin();
		advance(iter, index);
		return (*iter)->getSprite();
	}

	void moveAlienArmy(RenderWindow& win)
	{

		if (alienHolder2.size() != 0)
		{
			Vector2f pos;
			if (alienArmyRight)
			{
				list<alien*>::iterator iter;

				for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
				{
					pos = (*iter)->getSprite().getPosition();
					pos.x += 5.0f;
					(*iter)->getSprite().setPosition(pos);
				}

			}

			list<alien*>::iterator it;
			it = alienHolder2.begin();
			advance(it, alienHolder2.size() - 1);
			if ((*it)->getSprite().getPosition().x >= win.getSize().x - 35)
			{
				alienArmyRight = false;
				alienArmyLeft = true;
				counter++;

				if (counter == 6)
				{
					dropAlienArmy = true;
				}
			}

			if (alienArmyLeft)
			{
				list<alien*>::iterator iter;

				for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
				{
					(*iter)->getSprite().setPosition((*iter)->getSprite().getPosition().x - 5, (*iter)->getSprite().getPosition().y);
				}
			}

			it = alienHolder2.begin();
			advance(it, 0);
			if ((*it)->getSprite().getPosition().x <= 0)
			{
				alienArmyLeft = false;
				alienArmyRight = true;
			}

			if (dropAlienArmy)
			{
				list<alien*>::iterator iter;

				for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
				{
					(*iter)->getSprite().setPosition((*iter)->getSprite().getPosition().x, (*iter)->getSprite().getPosition().y + 100);
				}

				dropAlienArmy = false;
				counter = 0;
			}
		}
	}
};


