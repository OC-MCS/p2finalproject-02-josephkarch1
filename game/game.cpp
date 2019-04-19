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

void handleMouseUp(Vector2f mousePos, enum gameControl1);

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Kevin Durant is a Traitor!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// variables
	int timer = 0;

	// control game states with bool
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
		Event event;
		Vector2f mousePos;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}

			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					gameProjectiles.spaceBarDown(ptrGameShip);
				}

			}

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

			gameProjectiles.draw(window);

			window.display();

			if (gameAlienArmy.getSize() == 0)
			{
				gameControl1 = level2;
				gameAlienArmy.refillAlienArmyLevel1();
				gameProjectiles.clearAllProjectiles();
				controlGameUI.setLevel(2);
			}

			if (controlGameUI.getLives() == -1)
			{
				gameControl1 = lose;
				controlGameUI.resetUIVariables();
				gameProjectiles.clearAllProjectiles();
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
			gameAlienArmy.moveAlienArmy(window);
			gameAlienArmy.draw2(window);

			// Draw Projectiles
			gameProjectiles.missileShoot();
			gameProjectiles.missileOutOfBounds();
			gameProjectiles.bombFire(&gameAlienArmy, timer);
			gameProjectiles.bombDrop();
			
			// check for damage conditions
			gameProjectiles.hitCheck(&gameShip, &gameAlienArmy, &controlGameUI);
			gameAlienArmy.heightCheck(&gameShip, &gameAlienArmy, &controlGameUI);

			gameProjectiles.draw(window);

			window.display();

			if (gameAlienArmy.getSize() == 0)
			{
				gameControl1 = win;
				gameAlienArmy.refillAlienArmyLevel1();
				gameProjectiles.clearAllProjectiles();
				controlGameUI.setLevel(1);

			}

			if (controlGameUI.getLives() == -1)
			{
				gameControl1 = lose;
				controlGameUI.resetUIVariables();
				gameProjectiles.clearAllProjectiles();
			}
		}
		timer++;

	
	}

	return 0;
}

