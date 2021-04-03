/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:02:16 by vcordeir          #+#    #+#             */
/*   Updated: 2021/04/03 11:06:34 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void update()
{
	int move_step_x;
	int move_step_y;
	int new_px;
	int new_py;

	g_player->pa += g_player->inca * g_player->ang_speed;
	if (g_player->pa > 2 * PI)
		g_player->pa -= 2 * PI;
	if (g_player->pa < 0)
		g_player->pa += 2 * PI;
	move_step_x = g_player->incx *  g_player->lin_speed;
	move_step_y = g_player->incy *  g_player->lin_speed;
	new_px = g_player->px + move_step_x;
	new_py = g_player->py + move_step_y;
	if (!has_wall(new_px, new_py)) {
		g_player->px = new_px;
		g_player->py = new_py;
	}
	display();
}
