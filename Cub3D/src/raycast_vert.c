#include "../include/cub.h"

static	void	intercept(void)
{
	/* Initialize some variables */
	g_vert_inpt->found_vert_wall_hit = FALSE;
	g_vert_inpt->vert_wall_hit_x = 0;
	g_vert_inpt->vert_wall_hit_y = 0;
	g_vert_inpt->vert_wall_content = 0;

	/* Find the x-coordinate of the closest vertical grid intersection */
	g_vert_inpt->xintercept = floor(g_player->px / TILE_SIZE) * TILE_SIZE;
	g_vert_inpt->xintercept += g_ray->is_ray_facing_right ? TILE_SIZE : 0;

	/* Find the y-coordinate of the closest horizontal grid intersection */
	g_vert_inpt->yintercept = g_player->py + \
		(g_vert_inpt->xintercept - g_player->px) * tan(g_ray->ray_angle);

	/* Calculate the increment xstep and ystep */
	g_vert_inpt->xstep = TILE_SIZE;
	g_vert_inpt->xstep *= g_ray->is_ray_facing_left ? -1 : 1;
	g_vert_inpt->ystep = TILE_SIZE * tan(g_ray->ray_angle);
	g_vert_inpt->ystep *= (g_ray->is_ray_facing_up && \
							g_vert_inpt->ystep > 0) ? -1 : 1;
	g_vert_inpt->ystep *= (g_ray->is_ray_facing_down && \
							g_vert_inpt->ystep < 0) ? -1 : 1;
}

static	void	hit_wall(float touch_x, float touch_y, float x, float y)
{
	g_vert_inpt->vert_wall_hit_x = touch_x;
	g_vert_inpt->vert_wall_hit_y = touch_y;
	g_vert_inpt->vert_wall_content = \
					map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)];
	g_vert_inpt->found_vert_wall_hit = TRUE;
}

void raycast_vert(void)
{
	float next_vert_touch_x;
	float next_vert_touch_y;
	float x_check;
	float y_check;

	next_vert_touch_x = g_vert_inpt->xintercept;
	next_vert_touch_y = g_vert_inpt->yintercept;
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= WINDOW_WIDTH \
			&& next_vert_touch_y >= 0 && next_vert_touch_y <= WINDOW_HEIGHT)
	{
		x_check = next_vert_touch_x + (g_ray->is_ray_facing_left ? -1 : 0);
		y_check = next_vert_touch_y;
		if (has_wall(x_check, y_check))
		{
			hit_wall(next_vert_touch_x, next_vert_touch_y, x_check, y_check);
			break;
		} else {
			next_vert_touch_x += g_vert_inpt->xstep;
			next_vert_touch_y += g_vert_inpt->ystep;
		}
	}
}
