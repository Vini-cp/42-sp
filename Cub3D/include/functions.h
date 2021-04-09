#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	draw_square (int x, int y, int size, int color);
void	draw_line (double alpha, int len, int color);
void    draw_map();
void	draw_player();
void	move_player();
void	setup();
int 	update();
int 	end_game();
int     key_touch();

#endif
