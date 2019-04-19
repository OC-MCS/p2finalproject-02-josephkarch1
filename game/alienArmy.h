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
	list<alien*> alienHolder2;				// list which holds all the aliens
	textureManager* textureManagerHolder;	// pointer to the texture manager so the class can access textures
	bool alienArmyRight = true;				// bool which controls if the alien army is moving right
	bool alienArmyLeft = false;				// bool which controls if the alien army is moving left
	bool dropAlienArmy = false;				// bool which controls if the army needs to drop down a level
	int counter = 0;						// counter
	

public:

	alienArmy(textureManager* ptr)
	{
		int startingX = -20;
		int startingY = 100;

		textureManagerHolder = ptr;

		for (int x = 1; x < 11; x++)
		{
			alien* tempAlien;

			tempAlien = new alien(startingX + (x * 60), startingY, ptr);
			alienHolder2.push_back(tempAlien);
		}
	}

//================================================================================
// getSize: returns the size of the alien holder list
// parameters: N/A
// return type: int
//================================================================================
	int getSize()
	{
		return alienHolder2.size();
	}

//================================================================================
// heightCheck: checks to make sure that the alien army didn't decend past a certain point.
// if the army goes too low, life is lost.
// parameters: ship* ship1, alienArmy* army1, gameUI* gameControl
// return type: void
//================================================================================
	void heightCheck(ship* ship1, alienArmy* army1, gameUI* gameControl)
	{
		// go through the list of aliens, check if any are below a certain line
		list<alien*>::iterator iter;

		bool tooLow = false;

		for (iter = alienHolder2.begin(); !tooLow && iter != alienHolder2.end();)
		{
			
			if ((*iter)->getSprite().getPosition().y >= 375)
			{
				army1->refillAlienArmyLevel1();
				ship1->resetShipToStart();
				gameControl->setLives();
				tooLow = true;
			}

			else
			{
				iter++;
			}
		}
	}

//================================================================================
// draw: draws the list of aliens
// parameters: RenderWindow& win
// return type: void
//================================================================================
	void draw(RenderWindow& win)
	{
		list<alien*>::iterator iter;

		for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
		{
			win.draw((*iter)->getSprite());
		}
	}

//================================================================================
// setSpriteA: changes the default alien sprite to the level one sprite
// parameters: N/A
// return type: void
//================================================================================
	void setSpriteA()
	{
		list<alien*>::iterator iter;

		for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
		{
			(*iter)->setSpriteA();
		}
	}

//================================================================================
// setSpriteB: changes the default alien sprite to the level two sprite
// parameters: N/A
// return type: void
//================================================================================
	void setSpriteB()
	{
		list<alien*>::iterator iter;

		for (iter = alienHolder2.begin(); iter != alienHolder2.end(); iter++)
		{
			(*iter)->setSpriteB();
		}
	}

//================================================================================
// deleteAlien: deletes an alien of a particular index on the list
// parameters: int index
// return type: void
//================================================================================
	void deleteAlien(int index)
	{
		list<alien*>::iterator iter;

		iter = alienHolder2.begin();
		advance(iter, index);
		iter = alienHolder2.erase(iter);
	}

//================================================================================
// getSprite: gets the address to a sprite of a particular index from the list
// parameters: int index
// return type: Sprite&
//================================================================================
	Sprite& getSprite(int index)
	{
		list<alien*>::iterator iter;

		iter = alienHolder2.begin();
		advance(iter, index);
		return (*iter)->getSprite();
	}

//================================================================================
// refillAlienArmyLevel1: refills the list of aliens with 10 new aliens.  In the process 
// deletes any old aliens on the list
// parameters: n/a
// return type: void
//================================================================================
	void refillAlienArmyLevel1()
	{
		// delete everything in the old list
		list<alien*>::iterator iter;

		for (iter = alienHolder2.begin(); iter != alienHolder2.end();)
		{
				iter = alienHolder2.erase(iter);
		}

		// create a new list of 10 aliens
		int startingX = -20;
		int startingY = 100;

		for (int x = 1; x < 11; x++)
		{
			alien* tempAlien;

			tempAlien = new alien(startingX + (x * 60), startingY, textureManagerHolder);
			alienHolder2.push_back(tempAlien);
		}
	};
//================================================================================
// moveAlienArmy: goes through the loop / list and moves each alien in the list. 
// causes the entire line of aliens to move back and forth twice, and then drop down
// parameters: RenderWindow& win
// return type: void
//================================================================================
	void moveAlienArmy(RenderWindow& win)
	{

		if (alienHolder2.size() != 0)
		{
			Vector2f pos;

			// moves the alien army right
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

				if (counter == 2)
				{
					dropAlienArmy = true;
				}
			}

			// moves the alien army left
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

			// drops the alien army
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


