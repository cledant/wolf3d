/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:26:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/08 10:38:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_collision(t_mlx *e, double angle, size_t d_collision)
{
	double	value[2];
	double	dist;

	value [0] = angle + (FOV / 2);
	value [1] = FOV / 2;
	if (ft_select_ray(e, value, e->x_player, e->y_player) > d_collision)
	{
		value [0] = angle;
		value [1] = 0;
		if (ft_select_ray(e, value, e->x_player, e->y_player) > d_collision)
		{
			value [0] = angle - (FOV / 2);
			value [1] = -FOV / 2;
			if (ft_select_ray(e, value, e->x_player, e->y_player) > d_collision)
			{
				return (1);
			}
			return (0);
		}
		return (0);
	}
	else
		return (0);
}
