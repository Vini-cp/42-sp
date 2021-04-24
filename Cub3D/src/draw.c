#include "../include/cub.h"

void	draw_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (g_map->map[i][j] == '1')
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

void	draw_square(int x, int y, int size, int color)
{
	int	i;
	int	j;

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

void	draw_line(double alpha, int len, int color)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	aux;

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

void	draw_player(void)
{
	draw_square(g_player->px, g_player->py, PLAYER_SIZE, 0x00FFFF00);
	draw_line(g_player->pa, 25, 0x00FFFF00);
}

void draw_ray(void)
{
	int		iter;
	int		position;
	float	a;
	float	b;

	a = (g_player->py - g_ray->wall_hit_y) / (g_player->px - g_ray->wall_hit_x);
	b = (g_ray->wall_hit_y) - (a * g_ray->wall_hit_x);
	if((g_player->px - g_ray->wall_hit_x) > (g_player->py - g_ray->wall_hit_y))
	{
		iter = (g_player->px - g_ray->wall_hit_x > 0) ? -1 : 1;
		position = g_player->px;
		while (position != g_ray->wall_hit_x)
		{
			mlx_pixel_put(g_screen->mlx, g_screen->win, (int)(a * position - b), 
				position, 0x00ff0000);
			position += iter;
		}
	}
	else
	{
		a = 1 / a;
		b = -b * a;
		iter = (g_player->py - g_ray->wall_hit_y > 0) ? +1 : -1;
		position = g_player->py;
		while (position != g_ray->wall_hit_y)
		{
			mlx_pixel_put(g_screen->mlx, g_screen->win, position,
				(int)(a * position - b), 0x00ff0000);
			position += iter;
		}
	}
}
