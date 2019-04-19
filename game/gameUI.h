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
	RectangleShape outerBorder;						// makes the outer border of the entire game / UI for the game
	RectangleShape topMenuBorder;					// makes the top information bar
	string lives = "3";								// a string which represents the number of lives. used for outputting to info bar
	string level = "1";								// a string which represents the level. used for output to info bar
	string title = "Kevin Durant is a Traitor!";	// a string which goes on the info bar
	string score = "0";								// a string which represents the score, or number of aliens killed. used for outputting to the info bar

	int scoreInt = 0;								// an int which represents the score. used to do math on the score value then convert to string
	int livesInt = 3;								// an int which represents the number of lives. used to do math on the lives number then covert to string
	int levelInt = 1;								// an int which represents the level number. It is used to do math on the level number and then is converted to a string



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

		// Draw the fill information on the top  info bar of the UI
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

//================================================================================
// getLives: getter function which returns the number of lives as an int
// parameters: N/A
// return type: int
//================================================================================
	int getLives()
	{
		return livesInt;
	}

//================================================================================
// setLives: setter for the lives string and int variables
// parameters: N/A
// return type: void
//================================================================================
	void setLives()
	{
		string tempString;

		livesInt--;
		tempString = to_string(livesInt);

		lives = tempString;
	}

//================================================================================
// setScore: setter for the score string and int variables
// parameters: N/A
// return type: void
//================================================================================
	void setScore()
	{
		string tempString;

		scoreInt++;
		tempString = to_string(scoreInt);

		score = tempString;
	}

//================================================================================
// setLevel: setter for the lvel string and int variables
// parameters: int
// return type: void
//================================================================================
	void setLevel(int int1)
	{
		string tempString;

		tempString = to_string(int1);

		level = tempString;
	}

//================================================================================
// resetUIVariables: resets the score, lives and level variablesi n the UI
// parameters: none
// return type: void
//================================================================================
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
