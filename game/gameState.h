//#pragma once
//#include <iostream>
//using namespace std;
//#include <SFML/Graphics.hpp>
//using namespace sf;
//
//class gameState
//{
//
//private:
//	bool startingPage;
//	bool levelOne;
//	bool levelTwo;
//	bool endingPage;
//
//public:
//	gameState()
//	{
//		startingPage = true;
//		levelOne = false;
//		levelTwo = false;
//		endingPage = false;
//	}
//
//	void checkGameState(RenderWindow& win)
//	{
//		if (startingPage)
//		{
//			drawStartingPage(win);
//		}
//
//		if (levelOne)
//		{
//
//		}
//
//		if (levelTwo)
//		{
//
//		}
//
//		if (endingPage)
//		{
//
//		}
//	}
//
//	void drawStartingPage(RenderWindow& win2)
//	{
//
//		bool buttonClicked = false;
//		while (!buttonClicked)
//		{
//			RectangleShape startButton;
//
//			Font font;
//			if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
//				die("couldn't load font");
//
//
//			Vector2f sqPos3(100, 100);
//			startButton.setPosition(sqPos3);
//			startButton.setOutlineColor(Color::White);
//			startButton.setOutlineThickness(3);
//			startButton.setSize(Vector2f(300, 200));
//			startButton.setFillColor(Color::Blue);
//			win2.draw(startButton);
//
//			Text title1("START!", font, 16);
//			title1.setPosition(150, 150);
//			title1.setFillColor(sf::Color::White);
//			win2.draw(title1);
//			win2.display();
//
//
//		}
//
//
//		startingPage = false;
//		levelOne = true;
//	}
//
//	void die(string msg)
//	{
//		cout << msg << endl;
//		exit(-1);
//	}
//};
