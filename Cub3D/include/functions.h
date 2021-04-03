#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	draw_square (int x, int y, int size, int color);
void	draw_line (double alpha, int len, int color);
void    draw_map();
void	setup();
void	display();
void	update();
void	draw_player();
void	end_game();
int		key_pressed(int key);
int		key_released(int key);
int		has_wall(int x, int y);

#endif
