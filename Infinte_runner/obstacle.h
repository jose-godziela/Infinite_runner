#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include <iostream>

class Obstacle
{
private:
	Rectangle _rec;
	short _speed;
	Color _color;
public:
	Obstacle();
	Obstacle(short speed);
	~Obstacle();
	void set_color(Color color);
	void set_rec(Rectangle rec);
	void set_speed(short speed);
	short get_speed();
	Color get_color();
	Rectangle get_rec();
	void update();
};



#endif