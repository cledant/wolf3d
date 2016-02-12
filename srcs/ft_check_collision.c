/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:26:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 11:30:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_collision(t_mlx *e, double angle, size_t d_collision)
{
	double	value[4];
	int		wall;
	double	int_coord[2];

	wall = 0;
	value [0] = angle + (FOV / 2);
	if (value[0] >= 360)
		value[0] = value[0] - 360;
	if (value[0] <= -360)
		value[0] = value[0] + 360;
	value [1] = FOV / 2;
	value [2] = value[0] / (double)180;
	value [3] = M_PI * (FOV / 2) / (double)180;
	if (ft_select_ray(e, value, &wall, &int_coord) > d_collision)
	{
		value [0] = angle;
		if (value[0] >= 360)
			value[0] = value[0] - 360;
		if (value[0] <= -360)
			value[0] = value[0] + 360;
		value [1] = 0;
		value [2] = value[0] / (double)180;
		value [3] = 0;
		if (ft_select_ray(e, value, &wall, &int_coord) > d_collision)
		{
			value [0] = angle - (FOV / 2);
			if (value[0] >= 360)
				value[0] = value[0] - 360;
			if (value[0] <= -360)
				value[0] = value[0] + 360;
			value [1] = -FOV / 2;
			value [2] = value[0] / (double)180;
			value [3] = M_PI * (-FOV / 2) / (double)180;
			if (ft_select_ray(e, value, &wall, &int_coord) > d_collision)
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
