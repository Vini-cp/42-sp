#include "../include/cub.h"

static	void	intercept(void)
{
	/* Initialize some variables */
	g_horz_inpt->found_horz_wall_hit = FALSE;
	g_horz_inpt->horz_wall_hit_x = 0;
	g_horz_inpt->horz_wall_hit_y = 0;
	g_horz_inpt->horz_wall_content = 0;

	/* Find the y-coordinate of the closest horizontal grid intersection */
	g_horz_inpt->yintercept = floor(g_player->py / TILE_SIZE) * TILE_SIZE;
	g_horz_inpt->yintercept += g_ray->is_ray_facing_down ? TILE_SIZE : 0;

	/* Find the x-coordinate of the closest horizontal grid intersection */
	g_horz_inpt->xintercept = g_player->px + \
	(g_horz_inpt->yintercept - g_player->py) / tan(g_ray->ray_angle);

	/* Calculate the increment xstep and ystep */
	g_horz_inpt->ystep = TILE_SIZE;
	g_horz_inpt->ystep *= g_ray->is_ray_facing_up ? -1 : 1;
	g_horz_inpt->xstep = TILE_SIZE / tan(g_ray->ray_angle);
	g_horz_inpt->xstep *= (g_ray->is_ray_facing_left && \
							g_horz_inpt->xstep > 0) ? -1 : 1;
	g_horz_inpt->xstep *= (g_ray->is_ray_facing_right && \
							g_horz_inpt->xstep < 0) ? -1 : 1;
}

static	void	hit_wall(float touch_x, float touch_y, float x, float y)
{
	g_horz_inpt->horz_wall_hit_x = touch_x;
	g_horz_inpt->horz_wall_hit_y = touch_y;
	g_horz_inpt->horz_wall_content = \
					g_map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)];
	g_horz_inpt->found_horz_wall_hit = TRUE;
}

void raycast_horz(void)
{
	float next_hor_touch_x;
	float next_hor_touch_y;
	float x_check;
	float y_check;

	next_hor_touch_x = g_horz_inpt->xintercept;
	next_hor_touch_y = g_horz_inpt->yintercept;
	while (next_hor_touch_x >= 0 && next_hor_touch_x <= WINDOW_WIDTH \
			&& next_hor_touch_y >= 0 && next_hor_touch_y <= WINDOW_HEIGHT)
	{
		x_check = next_hor_touch_x;
		y_check = next_hor_touch_y + (g_ray->is_ray_facing_up ? -1 : 0);
		if (has_wall(x_check, y_check))
		{
			hit_wall(next_hor_touch_x, next_hor_touch_y, x_check, y_check);
			break;
		} else
		{
			next_hor_touch_x += g_horz_inpt->xstep;
			next_hor_touch_y += g_horz_inpt->ystep;
		}
	}
}
