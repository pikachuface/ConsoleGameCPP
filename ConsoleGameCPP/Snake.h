#pragma once
#include<vector>
#include"GameObject.h"
#include"directions.h"
class Snake
{
public:
	std::vector<GameObject> body;
	int lives;
private:
	Directions curDir = Directions::None;
	Directions lastDir = Directions::None;
public:
	Snake(GameObject head, int lives = 1);
	Snake();
	void ChangeDir(Directions newDir);
	bool Move();
	void addBodyPart(GameObject bodyPart);
private:
};

