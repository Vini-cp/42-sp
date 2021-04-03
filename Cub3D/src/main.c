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

t_screen	*g_screen;
t_player	*g_player;
t_map		*g_map;

void display()
{
	draw_map();
	draw_player();
}

int	main(void)
{
	setup();
	mlx_hook(g_screen->win, 02, 1L<<0, key_pressed, 0);
	mlx_hook(g_screen->win, 03, 1L<<1, key_released, 0);
	// mlx_key_hook(g_win, buttons, 0);
	// mlx_loop_hook(g_mlx, draw_bkgd, 0);
	mlx_loop(g_screen->mlx);
}
