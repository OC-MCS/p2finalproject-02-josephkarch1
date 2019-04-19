#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <string>


void die(string msg);

class gameUI
{
private:
	RectangleShape outerBorder;
	RectangleShape topMenuBorder;
	string lives = "3";
	string level = "1";
	string title = "Kevin Durant is a Traitor!";
	string score = "0";

	int scoreInt = 0;
	int livesInt = 3; 
	int levelInt = 1;



public:
	gameUI(int x)
	{

	};

	void draw(RenderWindow& win)
	{
		// Set Background Texture and draw		
		
		Sprite background;
		Texture starsTexture;

		if (!starsTexture.loadFromFile("stars.png"))
		{
			cout << "Unable to load stars texture!" << endl;
			exit(EXIT_FAILURE);
		}

		background.setTexture(starsTexture);
		win.draw(background);

		// Draw outter border
		Vector2f sqPos2(3, 3);
		outerBorder.setPosition(sqPos2);
		outerBorder.setOutlineColor(Color::White);
		outerBorder.setOutlineThickness(3);
		outerBorder.setSize(Vector2f(794, 594));
		outerBorder.setFillColor(Color::Transparent);
		win.draw(outerBorder);

		// Draw top border for title area 
		Vector2f sqPos3(3, 3);
		topMenuBorder.setPosition(sqPos3);
		topMenuBorder.setOutlineColor(Color::White);
		topMenuBorder.setOutlineThickness(3);
		topMenuBorder.setSize(Vector2f(794, 30));
		topMenuBorder.setFillColor(Color::White);
		win.draw(topMenuBorder);

		// fill information on the top bar
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text title1("level: ", font, 16);
		title1.setPosition(5, 5);
		title1.setFillColor(sf::Color::Blue);
		win.draw(title1);

		Text title2(level, font, 16);
		title2.setPosition(50, 5);
		title2.setFillColor(sf::Color::Blue);
		win.draw(title2);

		Text title3("Score: ", font, 16);
		title3.setPosition(200, 5);
		title3.setFillColor(sf::Color::Blue);
		win.draw(title3);

		Text title6(score, font, 16);
		title6.setPosition(250, 5);
		title6.setFillColor(sf::Color::Blue);
		win.draw(title6);

		Text title4("Lives: ", font, 16);
		title4.setPosition(725, 5);
		title4.setFillColor(sf::Color::Blue);
		win.draw(title4);

		Text title5(lives, font, 16);
		title5.setPosition(775, 5);
		title5.setFillColor(sf::Color::Blue);
		win.draw(title5);

		Text title7("Welcome to Durant Destroyer!", font, 16);
		title7.setPosition(350, 5);
		title7.setFillColor(sf::Color::Blue);
		win.draw(title7);
	}

	int getLives()
	{
		return livesInt;
	}

	void setLives()
	{
		string tempString;

		livesInt--;
		tempString = to_string(livesInt);

		lives = tempString;
	}

	void setScore()
	{
		string tempString;

		scoreInt++;
		tempString = to_string(scoreInt);

		score = tempString;
	}

	void setLevel(int int1)
	{
		string tempString;

		tempString = to_string(int1);

		level = tempString;
	}

	void resetUIVariables()
	{
		score = "0";
		lives = "3";
		level = "1";

		scoreInt = 0;
		livesInt = 3;
		levelInt = 1;
	}

};

//================================================================================
// die: this kills the process if text labels are unable to be drawn
// parameters: string
// return type: void
//================================================================================
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
