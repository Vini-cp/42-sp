/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:55:40 by vcordeir          #+#    #+#             */
/*   Updated: 2021/04/03 10:32:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void setup()
{
	g_screen = (t_screen *)malloc(sizeof(t_screen));
	g_screen->mlx = mlx_init();
	g_screen->win = mlx_new_window(
		g_screen->mlx,
		WIN_WIDTH,
		WIN_HEIGHT,
		"Cub3D");

	g_player = (t_player *)malloc(sizeof(t_player));
	g_player->px = 300;
	g_player->py = 300;
	g_player->pa = PI/2;
	g_player->lin_speed = 4;
    g_player->ang_speed = 3 * PI / 180;

	g_ray = (t_ray *)malloc(sizeof(t_ray));
	g_horz_inpt = (t_horz_intercept *)malloc(sizeof(t_horz_intercept));
	g_vert_inpt = (t_vert_intercept *)malloc(sizeof(t_vert_intercept));
}
