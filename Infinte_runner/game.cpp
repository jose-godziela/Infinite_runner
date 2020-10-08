#include "game.h"

Vector2 aux_pos;
Rectangle aux_rec;

void draw_lanes(int lane_counter, int lane_height, Color* colors);
void init_lines(int lanes_height, Color* colors);
void generate_enemy(int random_generator, list <Obstacle> &list_obs);
//aux
int random_generator, random_time;
int lane_counter = 16;
int lane_height = 50;

void game()
{

	float time_generation = 5 * FPS;

	Character* p = new Character();

	aux_rec.x = 50;
	aux_rec.y = 50;
	aux_rec.width = 20;
	aux_rec.height = 20;
	aux_pos.x = SCREEN_WIDTH / 2;
	aux_pos.y = (SCREEN_HEIGHT / 2) + (aux_rec.width / 2) + 5;

	p->set_jump_key(KEY_SPACE);
	p->set_mov_key_UP(KEY_UP);
	p->set_mov_key_DOWN(KEY_DOWN);
	p->set_mov_key_LEFT(KEY_LEFT);
	p->set_mov_key_RIGHT(KEY_RIGHT);
	p->set_rec(aux_rec);
	p->set_pos(aux_pos);

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST");

	Color* colors = new Color[lane_counter];
	list<Obstacle> list_obs;
	list<Obstacle>::iterator obs_iter;
	Obstacle obs;

	SetTargetFPS(FPS);

	init_lines(lane_counter, colors);

	random_time = GetRandomValue(0, time_generation);

	while (!WindowShouldClose())
	{
		//draw
		BeginDrawing();
		ClearBackground(BLACK);
		draw_lanes(lane_counter, lane_height, colors);

		DrawRectangleRec(p->get_rec(), BLACK);

		//update

		if (random_time <= 0)
		{
			random_time = GetRandomValue(0, time_generation);
			random_generator = GetRandomValue(MIN_ENEMIES_GENERATED, MAX_ENEMIES_GENERATED);
			generate_enemy(random_generator, list_obs);
		}
		cout << random_time << endl;
		random_time--;

		//if (list_obs.size() != NULL)
		//{
		//	obs = list_obs.front();
		//
		//	obs.update();
		//	if (obs.get_rec().x < 0)
		//	{
		//		list_obs.pop_front();
		//	}
		//
		//	DrawRectangleRec(obs.get_rec(), BLACK);
		//}

		if (list_obs.size() > 0)
		{
			for (obs_iter = list_obs.begin(); obs_iter != list_obs.end(); obs_iter++)
			{
				obs_iter->update();
				DrawRectangleRec(obs_iter->get_rec(), WHITE);
			}
		}
		

		//input

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
	delete[] colors;
}

void draw_lanes(int lane_counter, int lane_height, Color* colors)
{
	for (int i = 0; i < lane_counter; i++)
	{
		DrawRectangle(0, i * lane_height, GetScreenWidth(), lane_height, colors[i]);
	}

}

void init_lines(int lane_counter, Color* colors)
{
	for (int i = 0; i < lane_counter; i++)
	{
		colors[i].a = 255;
		colors[i].r = GetRandomValue(0, 255);
		colors[i].g = GetRandomValue(0, 255);
		colors[i].b = GetRandomValue(0, 255);
		if (i > 0)
		{
			//to avoid having the same colors
			while (colors[i].r == colors[i - 1].r
				&& colors[i].g == colors[i - 1].g
				&& colors[i].b == colors[i - 1].b)
			{
				colors[i].r = GetRandomValue(0, 255);
				colors[i].g = GetRandomValue(0, 255);
				colors[i].b = GetRandomValue(0, 255);
			}
		}
	}
}

void generate_enemy(int random_generator, list <Obstacle> &list_obs)
{
	Rectangle rec;
	for (int i = 0; i < random_generator; i++)
	{
		Obstacle obs = Obstacle();
		rec.width = 10;
		rec.height = 10;
		rec.y = (GetRandomValue(0,lane_counter) * lane_height) - 30;
		rec.x = GetScreenWidth() + rec.width;
		obs.set_rec(rec);
		list_obs.push_back(obs);
	}
}