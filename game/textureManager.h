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
	Texture bombTexture;
	
public:
	textureManager()
	{
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}

		if (!starsTexture.loadFromFile("stars.jpg"))
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

		if (!bombTexture.loadFromFile("bomb.png"))
		{
			cout << "Unable to load bomb texture!" << endl;
			exit(EXIT_FAILURE);
		}
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

	Texture &getBombTexture()
	{
		return bombTexture;
	}
};
