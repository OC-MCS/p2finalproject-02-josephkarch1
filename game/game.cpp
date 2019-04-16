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

	// create the classes to control the different aspects of the program
	gameUI controlGameUI(0);
	ship gameShip;
	alienArmy gameAlienArmy;

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
					// handle space bar
				}

			}
		}



		controlGameUI.draw(window);

		gameShip.moveShip();
		gameShip.checkBounds(window);
		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		gameShip.draw(window);

		gameAlienArmy.moveAlienArmy(window);
		gameAlienArmy.draw(window);
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

		timer++;

	}

	return 0;
}

