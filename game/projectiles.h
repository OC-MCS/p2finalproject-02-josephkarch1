#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "missiles.h"
#include "bombs.h"
#include "textureManager.h"
#include "ship.h"
#include "alienArmy.h"

class projectiles
{
private:
	list<bombs*> bombsHolder;
	list<missiles*> misssilesHolder;
	textureManager* holderPointer;

public:

	projectiles(textureManager* ptr)
	{
		holderPointer = ptr;
	}

	void hitCheck(ship* ship1, alienArmy* army1, gameUI* gameControl)
	{
		int index;
		list<missiles*>::iterator iter;

		for (iter = misssilesHolder.begin(); iter != misssilesHolder.end(); )
		{
			bool hit = false;
			for (int k = 0; k < army1->getSize() && !hit; k++)
			{
				if ((*iter)->getSprite().getGlobalBounds().intersects(army1->getSprite(k).getGlobalBounds()))
				{
					iter = misssilesHolder.erase(iter);
					army1->deleteAlien(k);
					hit = true;
					gameControl->setScore();

				}
			}
			if (!hit)
			{
				iter++;
			}
		}

		list<bombs*>::iterator iter2;

		for (iter2 = bombsHolder.begin(); iter2 != bombsHolder.end(); iter2++)
		{	
			if ((*iter2)->getSprite().getGlobalBounds().intersects(ship1->getSprite().getGlobalBounds()))
			{
				army1->refillAlienArmyLevel1();
				ship1->resetShipToStart();
				gameControl->setLives();
			}
		}
	}


	void bombFire(alienArmy* army1, int timer1)
	{
		int tempX;
		int tempY;
		int randomAlienIndex;
		srand(time(0));
		randomAlienIndex = rand() % army1->getSize();

		if (timer1 % 30 == 0)
		{
			bombs* tempBomb;

			tempBomb = new bombs(army1->getSprite(randomAlienIndex).getPosition().x, army1->getSprite(randomAlienIndex).getPosition().y - 5, holderPointer);
			bombsHolder.push_back(tempBomb);
		}
	}

	void bombDrop()
	{
		list<bombs*>::iterator iter;

		for (iter = bombsHolder.begin(); iter != bombsHolder.end(); iter++)
		{
			(*iter)->getSprite().setPosition((*iter)->getSprite().getPosition().x, (*iter)->getSprite().getPosition().y + 10);
		}
	}

	void missileShoot()
	{
		list<missiles*>::iterator iter;

		for (iter = misssilesHolder.begin(); iter != misssilesHolder.end(); iter++)
		{
			(*iter)->getSprite().setPosition((*iter)->getSprite().getPosition().x, (*iter)->getSprite().getPosition().y - 10);
		}
	}

	void bombOutOfBounds()
	{
		list<bombs*>::iterator iter;

		for (iter = bombsHolder.begin(); iter != bombsHolder.end(); )
		{
			if ((*iter)->getSprite().getPosition().y > 550)
			{
				iter = bombsHolder.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	void missileOutOfBounds()
	{
		list<missiles*>::iterator iter;

		for (iter = misssilesHolder.begin(); iter != misssilesHolder.end();)
		{
			if ((*iter)->getSprite().getPosition().y < 35)
			{
  				iter = misssilesHolder.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	void clearAllProjectiles()
	{
		list<bombs*>::iterator iter;

		for (iter = bombsHolder.begin(); iter != bombsHolder.end(); )
		{
				iter = bombsHolder.erase(iter);
		}

		list<missiles*>::iterator iter2;

		for (iter2 = misssilesHolder.begin(); iter2 != misssilesHolder.end();)
		{
				iter2 = misssilesHolder.erase(iter2);
		}
	}

	void spaceBarDown(ship* ptr)
	{
		missiles* tempMissile;

		tempMissile = new missiles(ptr->getSprite().getPosition().x, ptr->getSprite().getPosition().y - 5, holderPointer);
		misssilesHolder.push_back(tempMissile);
	}

	void draw(RenderWindow& win)
	{
		list<missiles*>::iterator iter;

		for (iter = misssilesHolder.begin(); iter != misssilesHolder.end(); iter++)
		{
			win.draw((*iter)->getSprite());
		}

		list<bombs*>::iterator iter2;

		for (iter2 = bombsHolder.begin(); iter2 != bombsHolder.end(); iter2++)
		{
			win.draw((*iter2)->getSprite());
		}
	}
};
