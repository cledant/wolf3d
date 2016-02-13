/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:55:48 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 20:22:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_struct(t_mlx *e)
{
	e->render = 0;
	e->alpha = 0;
	e->rad_alpha = 0;
	e->cos_rad_alpha = 1;
	e->sin_rad_alpha = 0;
	e->dist_to_proj_plane = (WIN_X / 2) / tan((M_PI * (90 - FOV) /
				(double)180));
	e->inc_alpha = FOV / ((double)WIN_X);
	e->x_player = PLAYER_X_START;
	e->y_player = PLAYER_Y_START;
	e->counter_chu = 0;
	e->speed = SPEED;
	e->x_mouse_old = WIN_X / 2;
}
