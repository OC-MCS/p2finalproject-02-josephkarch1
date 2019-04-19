//============================================================
// Joseph Karch
// Programming II - Assignment 7
// Due April 19, 2019
//============================================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameUI.h"
#include "alien.h"
#include "ship.h"
#include "alienArmy.h"
#include "projectiles.h"
#include "bombs.h"
#include "missiles.h"
#include "textureManager.h"


using namespace std;
using namespace sf; 


int main()
{
	// Set size of window
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Kevin Durant is a Traitor!");

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// start timer
	int timer = 0;

	// control game states with enum
	enum gameControl
	{
		start, level1, level2, win, lose
	}; 

	gameControl gameControl1 = start;


	// Load up the textures and set up the pointer to textures
	textureManager gameTextureManager;
	textureManager* ptrGameTextureManager;
	ptrGameTextureManager = &gameTextureManager;

	// create the classes to control the different aspects of the program
	gameUI controlGameUI(0);
	ship gameShip(ptrGameTextureManager);
	alienArmy gameAlienArmy(ptrGameTextureManager);
	projectiles gameProjectiles(&gameTextureManager);
	
	// create pointer to the ship
	ship* ptrGameShip;
	ptrGameShip = &gameShip;


	// Start the Animation Loop
	while (window.isOpen())
	{
		// needed to handle mouse and keyboard button clicks
		Event event;
		Vector2f mousePos;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}

			// handles pressing the spacebar
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					gameProjectiles.spaceBarDown(ptrGameShip);
				}

			}

			// handles the mouse clicks for buttons
			else if (event.type == Event::MouseButtonReleased && (gameControl1 == start || gameControl1 == win || gameControl1 == lose))
			{

				mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				
				if (gameTextureManager.getStartButton().getGlobalBounds().contains(mousePos) && gameControl1 == start)
				{
					gameControl1 = level1;
				}

				else if (gameTextureManager.getStartButton().getGlobalBounds().contains(mousePos) && gameControl1 == win)
				{
					gameControl1 = start;
					controlGameUI.resetUIVariables();
				}
				
				else if (gameTextureManager.getStartButton().getGlobalBounds().contains(mousePos) && gameControl1 == lose)
				{
					gameControl1 = start;
					controlGameUI.resetUIVariables();
				}
			}
		}
	
		// Draw the game's UI
		controlGameUI.draw(window);

		// Game state = start 
		if (gameControl1 == start)
		{
			gameTextureManager.drawStartButton(window);
			window.display();
			
		}

		// Game state = lose
		if (gameControl1 == lose)
		{
			gameTextureManager.drawLoseButton(window);
			window.display();
			controlGameUI.resetUIVariables();
		}

		// Game state = win
		if (gameControl1 == win)
		{
			gameTextureManager.drawWinButton(window);
			window.display();
			controlGameUI.resetUIVariables();
		}


		// Game state = level 1
		else if (gameControl1 == level1)
		{
			// Draw the Ship
			gameShip.moveShip();
			gameShip.checkBounds(window);
			gameShip.draw(window);

			// Draw the Alien
			gameAlienArmy.setSpriteA();
			gameAlienArmy.moveAlienArmy(window);
			gameAlienArmy.draw(window);

			// Draw Projectiles
			gameProjectiles.missileShoot();
			gameProjectiles.missileOutOfBounds();
			gameProjectiles.bombFire(&gameAlienArmy, timer);
			gameProjectiles.bombDrop();

			// Check for Damage Conditions
			gameProjectiles.hitCheck(&gameShip, &gameAlienArmy, &controlGameUI);
			gameAlienArmy.heightCheck(&gameShip, &gameAlienArmy, &controlGameUI);

			// Draw all projectiles
			gameProjectiles.draw(window);

			// display all the objects which were previoiusly drawn
			window.display();

			// if the alienArmy size is zero, change to level 2
			if (gameAlienArmy.getSize() == 0)
			{
				gameControl1 = level2;
				
				gameAlienArmy.refillAlienArmyLevel1();
				gameAlienArmy.setSpriteB();
				gameProjectiles.clearAllProjectiles();
				controlGameUI.setLevel(2);
			}

			// if the number of lives drops below zero, end the game
			if (controlGameUI.getLives() == -1)
			{
				gameControl1 = lose;
				controlGameUI.resetUIVariables();
				gameProjectiles.clearAllProjectiles();
				controlGameUI.setLevel(1);
			}
		}
		
		// game state = level2
 		else if (gameControl1 == level2)
		{
			// Draw the Ship
			gameShip.moveShip();
			gameShip.checkBounds(window);
			gameShip.draw(window);

			// Draw the Alien
			gameAlienArmy.setSpriteB();
			gameAlienArmy.moveAlienArmy(window);
			gameAlienArmy.draw(window);

			// Draw Projectiles
			gameProjectiles.missileShoot();
			gameProjectiles.missileOutOfBounds();
			gameProjectiles.bombFire(&gameAlienArmy, timer);
			gameProjectiles.bombDrop();
			
			// check for damage conditions
			gameProjectiles.hitCheck(&gameShip, &gameAlienArmy, &controlGameUI);
			gameAlienArmy.heightCheck(&gameShip, &gameAlienArmy, &controlGameUI);

			// draw all projectiles
			gameProjectiles.draw(window);
			
			// display all the objects that were "drawn" on the window
			window.display();

			// if the AlienArmy size is equal to zero, then end the game
			if (gameAlienArmy.getSize() == 0)
			{
				gameControl1 = win;
				
				gameAlienArmy.refillAlienArmyLevel1();
				gameAlienArmy.setSpriteA();
				gameProjectiles.clearAllProjectiles();
				controlGameUI.setLevel(1);

			}

			// if the number of lives drops below zero, end end the game
			if (controlGameUI.getLives() == -1)
			{
				gameControl1 = lose;
				gameAlienArmy.setSpriteA();
				controlGameUI.resetUIVariables();
				gameProjectiles.clearAllProjectiles();
				controlGameUI.setLevel(1);
			}
		}
		timer++;

	
	}

	return 0;
}

