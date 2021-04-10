#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <errno.h>
# include "libft.h"
# include "constants.h"
# include "functions.h"
# include <stdio.h>

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
	char			*resolution_width;
	char			*resolution_height;
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

typedef	struct		s_ray {
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			horz_hit_distance;
	float			vert_hit_distance;
	float			distance;
	int				was_hit_vertical;
	int 			was_hit_content;
	int				is_ray_facing_up;
	int				is_ray_facing_down;
	int 			is_ray_facing_left;
	int 			is_ray_facing_right;
} 					t_ray;

typedef	struct		s_horz_intercept {
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	int				found_horz_wall_hit;
	float			horz_wall_hit_x;
	float			horz_wall_hit_y;
	int				horz_wall_content;
} 					t_horz_intercept;

typedef	struct		s_vert_intercept {
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	int				found_vert_wall_hit;
	float			vert_wall_hit_x;
	float			vert_wall_hit_y;
	int				vert_wall_content;
} 					t_vert_intercept;

extern t_screen *g_screen;
extern t_player *g_player;
extern t_map *g_map;
extern t_ray *g_ray;
extern t_horz_intercept *g_horz_inpt;
extern t_vert_intercept *g_vert_inpt;

#endif
