#include "../include/cub.h"

static	void	define_ray_properties(void)
{
	g_ray->ray_angle = normalize_angle(g_ray->ray_angle);
	g_ray->is_ray_facing_down = g_ray->ray_angle > 0 && g_ray->ray_angle < PI;
	g_ray->is_ray_facing_up = !g_ray->is_ray_facing_down;
	g_ray->is_ray_facing_right = g_ray->ray_angle < 0.5 * PI || \
								g_ray->ray_angle > 1.5 * PI;
	g_ray->is_ray_facing_left = !g_ray->is_ray_facing_right;
}

static	float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

static	void	define_distance(void)
{
	g_ray->horz_hit_distance = g_horz_inpt->found_horz_wall_hit ? \
		distanceBetweenPoints(g_player->px, g_player->py, \
		g_horz_inpt->horz_wall_hit_x, g_horz_inpt->horz_wall_hit_y) : FLT_MAX;
	g_ray->vert_hit_distance = g_vert_inpt->found_vert_wall_hit ? \
		distanceBetweenPoints(g_player->px, g_player->py, \
		g_vert_inpt->vert_wall_hit_x, g_vert_inpt->vert_wall_hit_y) : FLT_MAX;
}

static	void	raycast(void)
{
	define_ray_properties();
	raycast_horz();
	raycast_vert();
	define_distance();
	if (g_ray->vert_hit_distance < g_ray->horz_hit_distance)
	{
		g_ray->distance = g_ray->vert_hit_distance;
		g_ray->wall_hit_x = g_vert_inpt->vert_wall_hit_x;
		g_ray->wall_hit_y = g_vert_inpt->vert_wall_hit_y;
		g_ray->was_hit_content = g_vert_inpt->vert_wall_content;
		g_ray->was_hit_vertical = TRUE;
	}
	else
	{
		g_ray->distance = g_ray->horz_hit_distance;
		g_ray->wall_hit_x = g_horz_inpt->horz_wall_hit_x;
		g_ray->wall_hit_y = g_horz_inpt->horz_wall_hit_y;
		g_ray->was_hit_content = g_horz_inpt->horz_wall_content;
		g_ray->was_hit_vertical = FALSE;
	}
}

void	raycast_all_rays(void)
{
	float	ray_angle;

	ray_angle = g_player->pa - (FOV_ANGLE / 2);
	while (ray_angle != g_player->pa + (FOV_ANGLE / 2))
	{
		g_ray->ray_angle = ray_angle;
		raycast();
		draw_line (g_ray->ray_angle, g_ray->distance, 0x00ff0000);
		ray_angle += FOV_ANGLE / NUM_RAYS;
	}
}
