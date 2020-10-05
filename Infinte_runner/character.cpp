#include "character.h"


Character::Character()
{
	std::cout << "He sido creado" << std::endl;
	_pos = {NULL,NULL};
	_mov_key_L = NULL;
	_mov_key_R = NULL;
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
}

void Character::set_jump_key(int jump_key)
{
	_jump_key = jump_key;
}

void Character::set_mov_key_L(int mov_key_L)
{
	_mov_key_L = mov_key_L;
}
void Character::set_mov_key_R(int mov_key_R)
{
	_mov_key_R = mov_key_R;
}

void Character::set_rec(Rectangle rec)
{
	_rec = rec;
}

Vector2 Character::get_pos() { return _pos; }

int Character::get_mov_key_L() { return _mov_key_L; }

int Character::get_mov_key_R() { return _mov_key_R; }

int Character::get_jump_key() { return _jump_key; }

Rectangle Character::get_rec() { return _rec; }
