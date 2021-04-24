#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	draw_square (int x, int y, int size, int color);
void	draw_line (double alpha, int len, int color);
void	draw_map();
void	draw_player();
void	draw_ray();
void	move_player();
void	setup();
void	raycast_all_rays();
void	raycast_horz();
void	raycast_vert();
int		update();
int		end_game();
int		key_touch();
int		read_map_file(char *file);
int		has_wall(int x, int y);
float	normalize_angle(float angle);

#endif
