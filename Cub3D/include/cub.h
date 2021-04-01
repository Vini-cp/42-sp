#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

/* -------------------------------------------------------------------------- */
/* --------------------------------- PLAYER --------------------------------- */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* --------------------------------- SCREEN --------------------------------- */
/* -------------------------------------------------------------------------- */

typedef	struct		s_screen
{
	void			*mlx;
	void			*win;
}					t_screen;

# define TILE_SIZE 64
# define WIN_WIDTH 512
# define WIN_HEIGHT 512
# define PLAYER_SIZE 8


extern t_screen *g_screen;
extern t_player *g_player;

/* -------------------------------------------------------------------------- */
/* ------------------------------ GAME CONTROLS ----------------------------- */
/* -------------------------------------------------------------------------- */

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363

/* -------------------------------------------------------------------------- */
/* ---------------------------------- MATH ---------------------------------- */
/* -------------------------------------------------------------------------- */

# define PI 3.14159265359


/* -------------------------------------------------------------------------- */
/* ---------------------------------- DRAW ---------------------------------- */
/* -------------------------------------------------------------------------- */

void	draw_square (int x, int y, int size, int color);
#endif
