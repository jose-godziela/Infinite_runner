#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include <iostream>

class Obstacle
{
private:
	Rectangle _rec;
	short _speed;
public:
	Obstacle();
	~Obstacle();
	void set_rec(Rectangle rec);
	Rectangle get_rec();
	void update();
};



#endif