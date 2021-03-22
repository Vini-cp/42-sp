#include "../include/cub.h"

void draw_player()
{
	int i;
	int j;

	i = px;
	while (i < px + PLAYER_SIZE)
	{
		j = py;
		while (j < py + PLAYER_SIZE)
		{
			mlx_pixel_put(g_mlx, g_win, i, j, 0x00FFFF00);
			j++;
		}
		i++;
	}
}
