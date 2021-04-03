/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_touch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:58:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/04/03 11:17:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int key_pressed(int key)
{
	if (key == ESC)
		end_game();
	if(key == LEFT)
		g_player->incx -= 1;
	if(key == RIGHT)
		g_player->incx += 1;
	if(key == UP)
		g_player->incy -= 1;
	if(key == DOWN)
		g_player->incy += 1;
	if(key == ROTATE_LEFT)
		g_player->inca += 1;
	if(key == ROTATE_RIGHT)
		g_player->inca -= 1;
	update();
	return (0);
}

int key_released(int key)
{
	if(key == LEFT)
		g_player->incx = 0;
	if(key == RIGHT)
		g_player->incx = 0;
	if(key == UP)
		g_player->incy = 0;
	if(key == DOWN)
		g_player->incy = 0;
	if(key == ROTATE_LEFT)
		g_player->inca = 0;
	if(key == ROTATE_RIGHT)
		g_player->inca = 0;
	update();
	return (0);
}
