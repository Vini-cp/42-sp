#include "../include/cub.h"

void draw_bkgd()
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
}
