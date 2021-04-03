#include "../include/cub.h"

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

// static	void	check_arguments(int argc, char **argv)
// {
// 	char	*file_extension;
// 	int		check_error;

// 	check_error = FALSE;
// 	if (argc < 2 || argc > 3)
// 		// check_error = TRUE;
// 	file_extension = ft_substr(*argv[1], ft_strlen(argv[1] - 4), 4);
// 	if (ft_strncmp(file_extension, ".cub\0", 5))
// 		// check_error = TRUE;
// 	if (ft_strncmp(*argv[2], "--save\0", 7))
// 		// check_error = TRUE;
	
// 	ft_memdel(file_extension);
// 	if (check_error)
// 		// error => ft_printf("Error\n%s\n", strerror(errno));
// 		// end_game()
// }

int	main(int argc, char **argv)
{
	// check_arguments(argc, argv);
	// check_resolution();
	// read_map_file(argv[1]);
	setup();
	// if (argv[2])
	// 	save_bmp_image();
	mlx_hook(g_screen->win, 17, 1L<<17, end_game, 0);
	mlx_hook(g_screen->win, 02, 1L<<0, key_pressed, 0);
	mlx_hook(g_screen->win, 03, 1L<<1, key_released, 0);
	mlx_loop(g_screen->mlx);
}
