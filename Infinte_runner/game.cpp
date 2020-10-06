#include "game.h"

Vector2 aux_pos;
Rectangle aux_rec;
Layer current_layer;

void game()
{
	Character* p = new Character();

	aux_pos.x = SCREEN_WIDTH / 2;
	aux_pos.y = SCREEN_HEIGHT / 2;
	aux_rec.x = 50;
	aux_rec.y = 50;
	aux_rec.width = 20;
	aux_rec.height = 20;

	p->set_jump_key(KEY_SPACE);
	p->set_mov_key_UP(KEY_UP);
	p->set_mov_key_DOWN(KEY_DOWN);
	p->set_mov_key_LEFT(KEY_LEFT);
	p->set_mov_key_RIGHT(KEY_RIGHT);
	p->set_rec(aux_rec);
	p->set_pos(aux_pos);


	InitWindow(1080, 720, "TEST");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		//draw
		DrawRectangleRec(p->get_rec(), RED);

		//update
		if (IsKeyPressed(p->get_mov_key_UP()))
		{
			std::cout << "Me muevo para arriba" << std::endl;
			aux_pos.y -= 50;
			p->set_pos(aux_pos);
		}
		if (IsKeyPressed(p->get_mov_key_DOWN()))
		{
			std::cout << "Me muevo para abajo" << std::endl;
			aux_pos.y += 50;
			p->set_pos(aux_pos);
		}

		if (IsKeyPressed(p->get_mov_key_LEFT()))
		{
			std::cout << "Me muevo para la izq" << std::endl;
			aux_pos.x -= 50;
			p->set_pos(aux_pos);
		}
		if (IsKeyPressed(p->get_mov_key_RIGHT()))
		{
			std::cout << "Me muevo para der" << std::endl;
			aux_pos.x += 50;
			p->set_pos(aux_pos);
		}
		EndDrawing();
	}

	
	delete p;
}




