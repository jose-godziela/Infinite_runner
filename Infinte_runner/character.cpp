#include "character.h"


Character::Character()
{
	std::cout << "He sido creado" << std::endl;
	_pos = {NULL,NULL};
	_mov_key_up = NULL;
	_mov_key_down = NULL;
	_mov_key_left = NULL;
	_mov_key_right = NULL;
	_jump_key = NULL;
	_lives = 6;
	_score = NULL;
	_rec = {NULL,NULL,NULL,NULL};
}
Character::~Character()
{
	std::cout << "He sido destruido" << std::endl;
}

void Character::set_pos(Vector2 pos)
{
	_pos = pos;
	_rec.x = _pos.x;
	_rec.y = _pos.y;
}

void Character::set_jump_key(int jump_key)
{
	_jump_key = jump_key;
}

void Character::set_mov_key_UP(int mov_key_UP)
{
	_mov_key_up = mov_key_UP;
}
void Character::set_mov_key_DOWN(int mov_key_DOWN)
{
	_mov_key_down = mov_key_DOWN;
}

void Character::set_rec(Rectangle rec)
{
	_rec = rec;
}

void Character::set_mov_key_LEFT(int mov_key_LEFT)
{
	_mov_key_left = mov_key_LEFT;
}

void Character::set_mov_key_RIGHT(int mov_key_RIGHT)
{
	_mov_key_right = mov_key_RIGHT;
}
void Character::set_score(int score)
{
	_score = score;
}

void Character::set_lives(int lives)
{
	_lives = lives;
}

void Character::set_alive(bool alive)
{
	_alive = alive;
}

Vector2 Character::get_pos() { return _pos; }

int Character::get_mov_key_UP() { return _mov_key_up; }

int Character::get_mov_key_DOWN() { return _mov_key_down; }

int Character::get_jump_key() { return _jump_key; }

Rectangle Character::get_rec() { return _rec; }

int Character::get_mov_key_LEFT() { return _mov_key_left; }
int Character::get_mov_key_RIGHT() { return _mov_key_right; }

int Character::get_score() { return _score; }

int Character::get_lives() { return _lives; }

bool Character::get_alive() { return _alive; }