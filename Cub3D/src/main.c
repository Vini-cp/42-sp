#include "../include/cub.h"

// int map[8][8] = {
// 	{1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 1, 0, 0, 0, 1, 1},
// 	{1, 0, 1, 0, 0, 0, 0, 1},
// 	{1, 0, 1, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1}
// };

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
// int	main(void)
{
	// check_arguments(argc, argv);
	if (argc != 2)
		return (0);
	// check_resolution();
	read_map_file(argv[1]);
	// read_map_file("maps/map3.cub\0");
		// if(! ... ERROR!)
	setup();
	// if (argv[2])
	// 	save_bmp_image();
	mlx_loop_hook(g_screen->mlx, update, 0);
	key_touch();
	mlx_loop(g_screen->mlx);
}
