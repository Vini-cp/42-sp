#include <mlx.h>
#include "include/cub.h"
#include "include/libft.h"
#include <stdio.h>

void	*g_mlx;
void	*g_win;
int		px;
int		py;
float	pa;

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

int ft_abs(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

void draw_line (float alpha, int len, int color)
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

int draw_bkgd()
{
	int i;
	int j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			mlx_pixel_put(g_mlx, g_win, i, j, 0x006B6E6F);
			j++;
		}
		i++;
	}
	return (0);
}

void display()
{
	// draw_bkgd();
	draw_map();
	draw_player();
}

int buttons(int key, void *param)
{
	if(key == 'a')
		px -= PLAYER_SIZE;
	if(key == 'd')
		px += PLAYER_SIZE;
	if(key == 'w')
		py -= PLAYER_SIZE;
	if(key == 's')
		py += PLAYER_SIZE;
	if(key == 65361)
	{
		pa += 0.1;
		pa += (pa > 2 * PI) ? -2 * PI : +0;
	}
	if(key == 65363)
	{
		pa -= 0.1;
		pa += (pa < 0) ? 2 * PI : +0;
	}
	// printf("%f\n", pa);
	display();
	return (0);
}

void init()
{
	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	px = 300;
	py = 300;
	pa = PI/2;
	draw_bkgd();
	display();
}

int     main(void)
{
	init();
	mlx_hook(g_win, 02, 1L<<0, buttons, 0);
	// mlx_key_hook(g_win, buttons, 0);
	// mlx_loop_hook(g_mlx, draw_bkgd, 0);
	mlx_loop(g_mlx);
}
