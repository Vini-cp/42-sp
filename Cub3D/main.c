#include <mlx.h>
#include "include/cub.h"

void	*g_mlx;
void	*g_win;

void init()
{
	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
}

void display()
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < WIN_WIDTH)
	{
		while (j < WIN_HEIGHT)
		{
			mlx_pixel_put(g_mlx, g_win, 500, 250, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

int     main(void)
{
	init();
	display();
	mlx_pixel_put(g_mlx, g_win, 512, 256, 0x00FFFFFF);
	mlx_loop(g_mlx);
}
