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

t_screen *g_screen;
t_player *g_player;

int ft_abs(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}


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
			mlx_pixel_put(g_screen->mlx, g_screen->win, i, j, color);
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

	x = g_player->px + cos(-alpha) * len;
	y = g_player->py + sin(-alpha) * len;
	if (ft_abs(g_player->px, x) >= ft_abs(g_player->py, y))
	{
		i = g_player->px;
		aux = (x > g_player->px) ? 1 : -1;
		while ((i += aux) != x)
		{
			j = tan(-alpha) * i + (g_player->py - tan(-alpha) * g_player->px);
			mlx_pixel_put(g_screen->mlx, g_screen->win, i, j, color);
		}
	}
	else
	{
		i = g_player->py;
		aux = (y > g_player->py) ? 1 : -1;
		while ((i += aux) != y)
		{
			j = (1 / tan(-alpha)) * i + (g_player->px - (1 / tan(-alpha)) * g_player->py);
			mlx_pixel_put(g_screen->mlx, g_screen->win, j, i, color);
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
                draw_square((j * TILE_SIZE) + 1, (i * TILE_SIZE) + 1, \
					TILE_SIZE, 0x00FFFFFF);
            else
            	draw_square((j * TILE_SIZE) + 1, (i * TILE_SIZE) + 1, \
					TILE_SIZE, 0x00000000);
            j++;
        }
		i++;
    }
}

void draw_player()
{
	draw_square(g_player->px, g_player->py, PLAYER_SIZE, 0x00FFFF00);
	draw_line(g_player->pa, 25, 0x00FFFF00);
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

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (1);
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);

	return ((map[mapGridIndexY][mapGridIndexX] == 1) ? 1 : 0);
}

/* -------------------------------------------------------------------------- */
/* --------------------------------- EVENT ---------------------------------- */
/* -------------------------------------------------------------------------- */

void display()
{
	draw_map();
	draw_player();
}

void update()
{
	int move_step_x;
	int move_step_y;
	int new_px;
	int new_py;

	g_player->pa += g_player->inca * g_player->ang_speed;
	if (g_player->pa > 2 * PI)
		g_player->pa -= 2 * PI;
	if (g_player->pa < 0)
		g_player->pa += 2 * PI;
	move_step_x = g_player->incx *  g_player->lin_speed;
	move_step_y = g_player->incy *  g_player->lin_speed;
	new_px = g_player->px + move_step_x;
	new_py = g_player->py + move_step_y;
	if (!has_wall(new_px, new_py)) {
		g_player->px = new_px;
		g_player->py = new_py;
	}
}

int key_pressed(int key)
{
	if(key == LEFT)
		g_player->incx -= 1;
	if(key == RIGHT)
		g_player->incx += 1;
	if(key == UP)
		g_player->incy -= 1;
	if(key == DOWN)
		g_player->incy += 1;
	if(key == ROTATE_LEFT)
		g_player->inca += 1;
	if(key == ROTATE_RIGHT)
		g_player->inca -= 1;
	update();
	display();
	return (0);
}

int key_released(int key)
{
	if(key == LEFT)
		g_player->incx = 0;
	if(key == RIGHT)
		g_player->incx = 0;
	if(key == UP)
		g_player->incy = 0;
	if(key == DOWN)
		g_player->incy = 0;
	if(key == ROTATE_LEFT)
		g_player->inca = 0;
	if(key == ROTATE_RIGHT)
		g_player->inca = 0;
	update();
	display();
	return (0);
}

/* -------------------------------------------------------------------------- */
/* ---------------------------------- SRC ----------------------------------- */
/* -------------------------------------------------------------------------- */

void setup()
{
	g_screen = (t_screen *)malloc(sizeof(t_screen));
	g_player = (t_player *)malloc(sizeof(t_player));
	g_screen->mlx = mlx_init();
	g_screen->win = mlx_new_window(g_screen->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	g_player->px = 300;
	g_player->py = 300;
	g_player->pa = PI/2;
	g_player->lin_speed = 4;
    g_player->ang_speed = 3 * PI / 180;
	display();
}


/* -------------------------------------------------------------------------- */
/* ---------------------------------- MAIN ---------------------------------- */
/* -------------------------------------------------------------------------- */

int     main(void)
{
	setup();
	mlx_hook(g_screen->win, 02, 1L<<0, key_pressed, 0);
	mlx_hook(g_screen->win, 03, 1L<<1, key_released, 0);
	// mlx_key_hook(g_win, buttons, 0);
	// mlx_loop_hook(g_mlx, draw_bkgd, 0);
	mlx_loop(g_screen->mlx);
}
