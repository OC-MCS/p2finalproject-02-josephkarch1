#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


class textureManager
{
private:
	Texture shipTexture;
	Texture starsTexture;
	Texture missileTexture;
	Texture enemyTexture;
	Texture enemyTexture2;
	Texture bombTexture;
	RectangleShape startButton;
	RectangleShape winButton;
	RectangleShape loseButton;
	
	
public:

	textureManager()
	{
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

		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}

	}

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

