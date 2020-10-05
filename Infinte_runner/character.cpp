#include "character.h"


Character::Character()
{
	std::cout << "He sido creado" << std::endl;
	_pos = {NULL,NULL};
	_mov_key_UP = NULL;
	_mov_key_DOWN = NULL;
	_jump_key = NULL;
	_lives = NULL;
	_score = NULL;
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
	_mov_key_UP = mov_key_UP;
}
void Character::set_mov_key_DOWN(int mov_key_DOWN)
{
	_mov_key_DOWN = mov_key_DOWN;
}

void Character::set_rec(Rectangle rec)
{
	_rec = rec;
}

Vector2 Character::get_pos() { return _pos; }

int Character::get_mov_key_UP() { return _mov_key_UP; }

int Character::get_mov_key_DOWN() { return _mov_key_DOWN; }

int Character::get_jump_key() { return _jump_key; }

Rectangle Character::get_rec() { return _rec; }
