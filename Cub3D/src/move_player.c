/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:03:36 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/31 22:04:17 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void			move_player(void)
{
	int move_step_x;
	int move_step_y;
	int new_px;
	int new_py;

	move_step_x = g_player->incx *  g_player->lin_speed;
	move_step_y = g_player->incy *  g_player->lin_speed;
	new_px = g_player->px + move_step_x;
	new_py = g_player->py + move_step_y;
	if (!has_wall(new_px, new_py)) {
		g_player->px = new_px;
		g_player->py = new_py;
	}
	g_player->pa += g_player->inca * g_player->ang_speed;
	g_player->pa = normalize_angle(g_player->pa);
}
