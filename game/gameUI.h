#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


void die(string msg);

class gameUI
{
private:
	RectangleShape outerBorder;
	RectangleShape topMenuBorder;
	string lives = "3";
	string level = "1";
	string title = "Space Invaders!";

public:
	gameUI(int x)
	{

	};

	void draw(RenderWindow& win)
	{
		// Set Background Texture and draw		
		
		Sprite background;
		Texture starsTexture;

		if (!starsTexture.loadFromFile("stars.jpg"))
		{
			cout << "Unable to load stars texture!" << endl;
			exit(EXIT_FAILURE);
		}

		background.setTexture(starsTexture);
		background.setScale(1.5, 1.5);
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
		topMenuBorder.setFillColor(Color::Black);
		win.draw(topMenuBorder);

		// fill information on the top bar
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text title1("level: ", font, 16);
		title1.setPosition(5, 5);
		title1.setFillColor(sf::Color::Green);
		win.draw(title1);

		Text title2(level, font, 16);
		title2.setPosition(50, 5);
		title2.setFillColor(sf::Color::Green);
		win.draw(title2);

		Text title3("Space Invaders!", font, 16);
		title3.setPosition(300, 5);
		title3.setFillColor(sf::Color::Green);
		win.draw(title3);

		Text title4("Lives: ", font, 16);
		title4.setPosition(725, 5);
		title4.setFillColor(sf::Color::Green);
		win.draw(title4);

		Text title5(lives, font, 16);
		title5.setPosition(775, 5);
		title5.setFillColor(sf::Color::Green);
		win.draw(title5);
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
