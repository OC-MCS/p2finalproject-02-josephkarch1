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
	list<bombs*> bombsHolder;				// linked list which holds all the bombs
	list<missiles*> misssilesHolder;		// linked list which holds all the missiles
	textureManager* holderPointer;			// holder pointer. holds the address of the texture manager so you can get access to the textures

public:

	projectiles(textureManager* ptr)
	{
		holderPointer = ptr;
	}

//================================================================================
// hitCheck: takes pointers to the alien army, ship and GameUI. It checks to see if
// the ship or alien army collides with a missile or bomb
// parameters: ship* ship1, alienArmy* army1, gameUI* gameControl
// return type: void
//================================================================================
	void hitCheck(ship* ship1, alienArmy* army1, gameUI* gameControl)
	{

		// check to see if the missiles intersect any of the aliens
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


		// check to see if the bombs intersect with the ship
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

//================================================================================
// bombFire: takes pointers to the alien army, and creates a new bomb in front of 
// a random alien. creates a new bomb every 1/2 second
// parameters: alienArmy* army1, int timer1
// return type: void
//================================================================================
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

//================================================================================
// bombDrop: goes through the loop and moves each bomb during the animation frame
// parameters: N/A
// return type: void
//================================================================================
	void bombDrop()
	{
		list<bombs*>::iterator iter;

		for (iter = bombsHolder.begin(); iter != bombsHolder.end(); iter++)
		{
			(*iter)->getSprite().setPosition((*iter)->getSprite().getPosition().x, (*iter)->getSprite().getPosition().y + 10);
		}
	}

//================================================================================
// missileShoot: goes through the loop and moves each missile during the animation frame
// parameters: N/A
// return type: void
//================================================================================
	void missileShoot()
	{
		list<missiles*>::iterator iter;

		for (iter = misssilesHolder.begin(); iter != misssilesHolder.end(); iter++)
		{
			(*iter)->getSprite().setPosition((*iter)->getSprite().getPosition().x, (*iter)->getSprite().getPosition().y - 10);
		}
	}

//================================================================================
// bombOutOfBounds: goes through the loop and checks to see if the bombs are outside the game window
// if a bomb is outside, it deletes it
// parameters: N/A
// return type: void
//================================================================================
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

//================================================================================
// missileOutOfBounds: goes through the loop and checks to see if the missiles is outside the game window
// if a missile is outside, it deletes it
// parameters: N/A
// return type: void
//================================================================================
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

//================================================================================
// clearAllProjectiles: goes through the loop and deletes all projectiles. It does this for both
// the bomb loop and the missile loop
// parameters: N/A
// return type: void
//================================================================================
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

//================================================================================
// spaceBarDown: handles the spacebar down event.  If the spacebar is down it makes a new
// missile and it puts the missile in front of the ship
// parameters: ship* ptr
// return type: void
//================================================================================
	void spaceBarDown(ship* ptr)
	{
		missiles* tempMissile;

		tempMissile = new missiles(ptr->getSprite().getPosition().x, ptr->getSprite().getPosition().y - 5, holderPointer);
		misssilesHolder.push_back(tempMissile);
	}

//================================================================================
// draw: draws all the projectiles.  It goes through both the bomb and the missile loops
// and it draws all the projectiles
// parameters: RenderWindow& win
// return type: void
//================================================================================
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
