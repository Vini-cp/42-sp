#include "../include/cub.h"

int	update(void)
{
	move_player();
	draw_map();
	draw_player();
	raycast_all_rays();
	return (0);
}
