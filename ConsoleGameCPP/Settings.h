#pragma once
#include"ansi_escapes.h"

class Settings
{
public:
	static const unsigned int mapWidth = 20;
	static const unsigned int mapHeight = 20;
	static const unsigned int timerInterval = 80;
	static const char defaultChar = ' ';
	static const char borderChar = '0';
	static const int borderCompensation = 3;
	static const int borderOffset = 1;

public:
	static void MakeBorder(Colors textBorderColor, Colors backgrColor)
	{
		for (int y = 0; y < mapHeight+borderCompensation; y++)
		{
			for (int x = 0; x < mapWidth+borderCompensation; x++)
			{
				if (y == 0 || y == mapHeight+borderCompensation - 1 || x == 0 || x == mapWidth+borderCompensation - 1)
				{
					setTextColor(textBorderColor);
					setBackgroundColor(backgrColor);
					moveCursorTo(y + Settings::borderOffset, (x + Settings::borderOffset)*2);
					printf("%c%c", borderChar,borderChar);
				}
			}
		}
	}

};
