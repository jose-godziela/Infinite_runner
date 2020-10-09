#include "obstacle.h"

Obstacle::Obstacle()
{
	_rec = { NULL,NULL,NULL,NULL };
	_speed = 10;
	_color = GRAY;
}

Obstacle::~Obstacle()
{

}

void Obstacle::set_color(Color color)
{
	_color = color;
}

void Obstacle::set_rec(Rectangle rec)
{
	_rec = rec;
}

void Obstacle::set_speed(short speed)
{
	_speed = speed;
}

Color Obstacle::get_color()
{
	return _color;
}

Rectangle Obstacle::get_rec()
{
	return _rec;
}

short Obstacle::get_speed()
{
	return _speed;
}

void Obstacle::update()
{
	_rec.x -= _speed;
}
