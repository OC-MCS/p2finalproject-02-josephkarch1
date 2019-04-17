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
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// variables
	int timer = 0;

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
		}


		// Draw the game's UI
		controlGameUI.draw(window);

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
		gameProjectiles.hitCheck(&gameShip, &gameAlienArmy);




		gameProjectiles.draw(window);
		


		window.display();


		timer++;

	}

	return 0;
}

