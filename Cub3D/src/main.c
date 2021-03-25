#include "../include/cub.h"
#include <stdio.h>

int map[8][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};


/* -------------------------------------------------------------------------- */
/* ---------------------------------- DRAW ---------------------------------- */
/* -------------------------------------------------------------------------- */

void draw_square (int x, int y, int size, int color)
{
	int i;
	int j;

	i = x;
	while (i < x + size)
	{
		j = y;
		while (j < y + size)
		{
			mlx_pixel_put(g_mlx, g_win, i, j, color);
			j++;
		}
		i++;
	}
}

void draw_line (double alpha, int len, int color)
{
	int x;
	int y;
	int i;
	int j;
	int aux;

	x = px + cos(-alpha) * len;
	y = py + sin(-alpha) * len;
	if (ft_abs(px, x) >= ft_abs(py, y))
	{
		i = px;
		aux = (x > px) ? 1 : -1;
		while ((i += aux) != x)
		{
			j = tan(-alpha) * i + (py - tan(-alpha) * px);
			mlx_pixel_put(g_mlx, g_win, i, j, color);
		}
	}
	else
	{
		i = py;
		aux = (y > py) ? 1 : -1;
		while ((i += aux) != y)
		{
			j = (1 / tan(-alpha)) * i + (px - (1 / tan(-alpha)) * py);
			mlx_pixel_put(g_mlx, g_win, j, i, color);
		}
	}
}

void    draw_map()
{
    int i;
    int j;

    i = 0;
    while (i < 8)
    {
		j = 0;
        while (j < 8)
        {
            if (map[i][j] == 1)
                draw_square((j * TILE_SIZE) + 1, (i * TILE_SIZE) + 1, TILE_SIZE, 0x00FFFFFF);
            else
            	draw_square((j * TILE_SIZE) + 1, (i * TILE_SIZE) + 1, TILE_SIZE, 0x00000000);
            j++;
        }
		i++;
    }
}

void draw_player()
{
	draw_square(px, py, PLAYER_SIZE, 0x00FFFF00);
	draw_line(pa, 25, 0x00FFFF00);
}

// int get_distance(float alpha)
// {
// 	int i;
// 	int j;
// 	int aux;
// 	int len;

// 	if ((alpha >= PI / 4 && alpha <= 3 * PI / 4) || (alpha >= PI / 4 && alpha <= 3 * PI / 4))
// 	{
// 		i = px;
// 		aux = (x > px) ? 1 : -1;
// 		while ((i += aux) != x)
// 		{
// 			j = tan(-alpha) * i + (py - tan(-alpha) * px);
// 			mlx_pixel_put(g_mlx, g_win, i, j, color);
// 		}
// 	}
// 	else
// 	{
// 		i = py;
// 		aux = (y > py) ? 1 : -1;
// 		while ((i += aux) != y)
// 		{
// 			j = (1 / tan(-alpha)) * i + (px - (1 / tan(-alpha)) * py);
// 			mlx_pixel_put(g_mlx, g_win, j, i, color);
// 		}
// 	}
// }

// void draw_fov(float alpha, float fov, int color)
// {
// 	int len;
// 	len = get_distance(alpha);
// }

/* -------------------------------------------------------------------------- */
/* --------------------------------- UTILS ---------------------------------- */
/* -------------------------------------------------------------------------- */

int has_wall(int x, int y) 
{
	int mapGridIndexX;
	int mapGridIndexY;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (1);
	mapGridIndexX = Math.floor(x / TILE_SIZE);
	mapGridIndexY = Math.floor(y / TILE_SIZE);

	return ((map[mapGridIndexY][mapGridIndexX] == 1) ? 1 : 0);
}

void display()
{
	draw_map();
	draw_player();
}


int key_pressed(int key, void *player)
{
	if(key == LEFT)
		player->incx -= 1;
	if(key == RIGHT)
		player->incx += 1;
	if(key == UP)
		player->incy -= 1;
	if(key == DOWN)
		player->incy += 1;
	if(key == ROTATE_LEFT)
		player->inca += 1;
	if(key == ROTATE_RIGHT)
		player->inca -= 1;
	update(&player);
		// pa += (pa > 2 * PI) ? -2 * PI : +0;
		// pa += (pa < 0) ? 2 * PI : +0;
	return (0);
}

int key_released(int key, void *player)
{
	if(key == LEFT)
		player->incx = 0;
	if(key == RIGHT)
		player->incx = 0;
	if(key == UP)
		player->incy = 0;
	if(key == DOWN)
		player->incy = 0;
	if(key == ROTATE_LEFT)
		player->inca = 0;
	if(key == ROTATE_RIGHT)
		player->inca = 0;
	update(&player);
	return (0);
}

void update(t_player **player)
{
	int ;
	int move_step_y;
	int new_px;
	int new_py;

	(*player)->pa += (*player)->pa * (*player)->ang_speed;
	move_step_x = (*player)->incx *  (*player)->lin_speed;
	move_step_y = (*player)->incy *  (*player)->lin_speed;
	new_px = (*player)->px + move_step_x;
	new_py = (*player)->py + move_step_y;
	if (!grid.has_wall(new_px, new_py)) {
		(*player)->px = new_px;
		(*player)->py = new_py;
	}
}

void setup(t_player *player)
{
	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	player->px = 300;
	player->py = 300;
	player->pa = PI/2;
	player->lin_speed = 4;
    player->ang_speed = 3 * PI / 180;
	display();
}


/* -------------------------------------------------------------------------- */
/* ---------------------------------- MAIN ---------------------------------- */
/* -------------------------------------------------------------------------- */

int     main(void)
{
	t_player *player;
	setup(&player);
	mlx_hook(g_win, 02, 1L<<0, key_pressed, &player);
	mlx_hook(g_win, 03, 1L<<1, key_released, &player);
	// mlx_key_hook(g_win, buttons, 0);
	// mlx_loop_hook(g_mlx, draw_bkgd, 0);
	mlx_loop(g_mlx);
}
