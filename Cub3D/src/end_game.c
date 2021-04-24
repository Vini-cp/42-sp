#include "../include/cub.h"

// static	void	free_player()
// {
// 	ft_memdel(g_player);
// }

// static	void	free_map()
// {
// 	ft_memdel(g_map->resolution);
// 	ft_memdel(g_map->north_text);
// 	ft_memdel(g_map->south_text);
// 	ft_memdel(g_map->west_text);
// 	ft_memdel(g_map->east_text);
// 	ft_memdel(g_map->sprite_text);
// 	ft_memdel(g_map->floor_rgb);
// 	ft_memdel(g_map->ceilling_rgb);
// 	ft_memdel(g_map->mapmap);
// 	// ft_memdel(g_map);
// }

// void	free_screen()
// {
// 	ft_memdel(&g_screen->mlx);
// 	ft_memdel(&g_screen->win);
// 	// ft_memdel(g_screen);
// }

// free_player();
// free_map();
// free_screen();

int	end_game(void)
{
	mlx_destroy_window(g_screen->mlx, g_screen->win);
	return (0);
}
