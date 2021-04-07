/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:43:38 by vcordeir          #+#    #+#             */
/*   Updated: 2021/04/03 11:03:17 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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

void draw_player()
{
	draw_square(g_player->px, g_player->py, PLAYER_SIZE, 0x00FFFF00);
	draw_line(g_player->pa, 25, 0x00FFFF00);
}

void display()
{
	draw_map();
	draw_player();
	// mlx_do_sync(g_screen->mlx);
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