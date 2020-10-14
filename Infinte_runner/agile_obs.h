#ifndef AGILE_OBS_H
#define AGILE_OBS_H

#include "raylib.h"
#include "obstacle.h"

class Agile_obs : public Obstacle
{
private:
	short _speed;
public:
	Agile_obs();
	~Agile_obs();
};


#endif
