#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	draw_square (int x, int y, int size, int color);
void	draw_line (double alpha, int len, int color);
void	draw_map(void);
void	draw_player(void);
void	draw_ray(void);
void	move_player(void);
void	setup(void);
void	raycast_all_rays(void);
void	raycast_horz(void);
void	raycast_vert(void);
int		update(void);
int		end_game(void);
int		key_touch(void);
int		read_map_file(char *file);
int		has_wall(int x, int y);
float	normalize_angle(float angle);

#endif
