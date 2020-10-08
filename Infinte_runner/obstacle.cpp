#include "obstacle.h"

Obstacle::Obstacle()
{
	_rec = { NULL,NULL,NULL,NULL };
	_speed = 10;
}

Obstacle::~Obstacle()
{

}

void Obstacle::set_rec(Rectangle rec)
{
	_rec = rec;
}

Rectangle Obstacle::get_rec()
{
	return _rec;
}

void Obstacle::update()
{
	_rec.x -= _speed;
}