#include "../include/cub.h"

static	int	key_pressed(int key)
{
	if (key == ESC)
		end_game();
	if (key == LEFT)
		g_player->incx -= 1;
	if (key == RIGHT)
		g_player->incx += 1;
	if (key == UP)
		g_player->incy -= 1;
	if (key == DOWN)
		g_player->incy += 1;
	if (key == ROTATE_LEFT)
		g_player->inca += 1;
	if (key == ROTATE_RIGHT)
		g_player->inca -= 1;
	return (0);
}

static	int	key_released(int key)
{
	if (key == LEFT)
		g_player->incx = 0;
	if (key == RIGHT)
		g_player->incx = 0;
	if (key == UP)
		g_player->incy = 0;
	if (key == DOWN)
		g_player->incy = 0;
	if (key == ROTATE_LEFT)
		g_player->inca = 0;
	if (key == ROTATE_RIGHT)
		g_player->inca = 0;
	return (0);
}

int	key_touch(void)
{
	mlx_hook(g_screen->win, 33, 1L <<17, end_game, 0);
	mlx_hook(g_screen->win, 02, 1L <<0, key_pressed, 0);
	mlx_hook(g_screen->win, 03, 1L <<1, key_released, 0);
	return (0);
}
