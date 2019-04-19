#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


class textureManager
{
private:
	Texture shipTexture;					// holds the texture for the ship / russell westbrook
	Texture starsTexture;					// holds the texture for the stars background / OKC thunder home court
	Texture missileTexture;					// holds the texture for the missile / cupcake
	Texture enemyTexture;					// holds the texture for the enemy / level 1 bad guy, kevin durant
	Texture enemyTexture2;					// holds the texture for the enemy / level 2 bad guy, angry kevin durant
	Texture bombTexture;					// holds the texture for the enemy bombs / kevin durant attack weapon, the NBA trophy
	RectangleShape startButton;				// shape of the start button, click and start the game
	RectangleShape winButton;				// shape of the win button, click and it restarts the game
	RectangleShape loseButton;				// shape of the lose button, click and it restarts the game
	
	
public:

	textureManager()
	{
		// load all the textures that will be used in the program
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}

		if (!starsTexture.loadFromFile("stars.png"))
		{
			cout << "Unable to load stars texture!" << endl;
			exit(EXIT_FAILURE);
		}

		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}

		if (!enemyTexture.loadFromFile("enemy.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}

		if (!enemyTexture2.loadFromFile("enemy2.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}

		if (!bombTexture.loadFromFile("bomb.png"))
		{
			cout << "Unable to load bomb texture!" << endl;
			exit(EXIT_FAILURE);
		}

		// load all the buttons that will be used in the game
		Vector2f sqPos1(300, 300);
		startButton.setPosition(sqPos1);
		startButton.setOutlineColor(Color::White);
		startButton.setOutlineThickness(3);
		startButton.setSize(Vector2f(200, 100));
		startButton.setFillColor(Color::White);

		Vector2f sqPos2(300, 300);
		winButton.setPosition(sqPos1);
		winButton.setOutlineColor(Color::White);
		winButton.setOutlineThickness(3);
		winButton.setSize(Vector2f(200, 100));
		winButton.setFillColor(Color::White);

		Vector2f sqPos3(300, 300);
		loseButton.setPosition(sqPos1);
		loseButton.setOutlineColor(Color::White);
		loseButton.setOutlineThickness(3);
		loseButton.setSize(Vector2f(200, 100));
		loseButton.setFillColor(Color::White);

		// load the fonts we will need
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

	}

//================================================================================
// drawStartButton: draws the start button
// parameters: RenderWindow& win
// return type: void
//================================================================================
	void drawStartButton(RenderWindow& win)
	{
		win.draw(startButton);

		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text startButtonTitle("Click to Start!", font, 24);
		startButtonTitle.setPosition(325, 325);
		startButtonTitle.setFillColor(sf::Color::Blue);
		win.draw(startButtonTitle);
	}

//================================================================================
// drawWinButton: draws the win button
// parameters: RenderWindow& win
// return type: void
//================================================================================
	void drawWinButton(RenderWindow& win)
	{
		win.draw(winButton);

		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text winButtonTitle("You Win! Click to Replay!", font, 16);
		winButtonTitle.setPosition(325, 325);
		winButtonTitle.setFillColor(sf::Color::Blue);
		win.draw(winButtonTitle);
	}

//================================================================================
// drawLoseButton: draws the lose button
// parameters: RenderWindow& win
// return type: void
//================================================================================
	void drawLoseButton(RenderWindow& win)
	{
		win.draw(loseButton);

		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

		Text loseButtonTitle("You Lose! Click to Replay!", font, 16);
		loseButtonTitle.setPosition(325, 325);
		loseButtonTitle.setFillColor(sf::Color::Blue);
		win.draw(loseButtonTitle);
	}


	// the following getter functions allow other classes to pull the textures from the texture manager to be used elsewhere

	RectangleShape &getStartButton()
	{
		return startButton;
	}

	Texture &getShipTexture()
	{
		return shipTexture;
	}

	Texture &getStarsTexture()
	{
		return starsTexture;
	}

	Texture &getMissileTexture()
	{
		return missileTexture;
	}

	Texture &getEnemyTexture()
	{
		return enemyTexture;
	}

	Texture &getEnemyTexture2()
	{
		return enemyTexture2;
	}

	Texture &getBombTexture()
	{
		return bombTexture;
	}
};

