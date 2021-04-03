#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "constants.h"

typedef	struct		s_player
{
	int				px;
	int				py;
	double			pa;
	int				incx;
	int				incy;
	double			inca;
	int				lin_speed;
    double			ang_speed;
}					t_player;

typedef	struct		s_screen
{
	void			*mlx;
	void			*win;
}					t_screen;

typedef	struct		s_map
{
	char			*resolution;
	char			*north_text;
	char			*south_text;
	char			*west_text;
	char			*east_text;
	char			*sprite_text;
	char			*floor_rgb;
	char			*ceilling_rgb;
	char			**map;
	int				width;
	int				height;
}					t_map;

extern t_screen *g_screen;
extern t_player *g_player;
extern int map[8][8];

void	draw_square (int x, int y, int size, int color);
void	draw_line (double alpha, int len, int color);
void    draw_map();
void	setup();
void	display();
void	update();
void	draw_player();
int		key_pressed(int key);
int		key_released(int key);
int		has_wall(int x, int y);

#endif
