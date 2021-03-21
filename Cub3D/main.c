#include <mlx.h>
#include "include/cub.h"
#include "include/libft.h"

void	*g_mlx;
void	*g_win;
int		px;
int		py;

int buttons(int key, void *param)
{
	if(key == 'a')
	{
		px -= 5;
		ft_printf("TEST");
	}
	if(key == 'd')
		px += 5;
	if(key == 'w')
		py -= 5;
	if(key == 's')
		py += 5;
	return (0);
}


void init()
{
	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	px = 400;
	py = 400;
}

int draw_player()
{
	int i;
	int j;

	i = px;
	while (i < px + 4)
	{
		j = py;
		while (j < py + 4)
		{
			mlx_pixel_put(g_mlx, g_win, i, j, 0x00FFFF00);
			j++;
		}
		i++;
	}
	return (0);
}

void display()
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

int     main(void)
{
	init();
	display();
	draw_player();
	mlx_key_hook(g_win, buttons, 0);
	mlx_loop_hook(g_win, draw_player, 0);
	mlx_loop(g_mlx);
}
