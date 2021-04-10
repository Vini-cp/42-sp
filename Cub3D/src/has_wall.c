#include "../include/cub.h"

int	has_wall(int x, int y)
{
	int mapGridIndexX;
	int mapGridIndexY;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (1);
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);

	return ((g_map->map[mapGridIndexY][mapGridIndexX] == '1') ? 1 : 0);
}
