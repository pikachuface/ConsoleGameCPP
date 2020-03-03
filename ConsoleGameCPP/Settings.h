#pragma once
#include"Tools.h"

class Settings
{
public:
	static const unsigned int mapWidth = 40;
	static const unsigned int mapHeight = 20;
	static const unsigned int clockTime = 150;
	static const char defaultChar = ' ';
	static const char wallChar = '0';
	static const int borderThicknes = 1;
public:
	static void MakeBorder()
	{
		for (int y = 0; y < mapHeight; y++)
		{
			if (y == 0 || y == mapHeight - 1)
			{
				for (int x = 0; x < mapWidth; x++)
				{
					Tools::printCharacter(x, y, wallChar);
				}
			}
			else
			{
				for (int x = 0; x < mapWidth; x++)
				{
					if (x == 0 || x == mapWidth - 1)
					{
						Tools::printCharacter(x, y, wallChar);
					}
				}
			}

		}
	}

};
