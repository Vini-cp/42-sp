#include "../include/cub.h"

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