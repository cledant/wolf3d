/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:26:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 20:56:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_set_value(double alpha, int beta, double (*value)[8])
{
	(*value)[0] = alpha;
	if ((*value)[0] >= 360)
		(*value)[0] = (*value)[0] - 360;
	if ((*value)[0] <= -360)
		(*value)[0] = (*value)[0] + 360;
	(*value)[1] = beta;
	(*value)[2] = M_PI * (*value)[0] / (double)180;
	if (beta == 0)
		(*value)[3] = 0;
	else
		(*value)[3] = M_PI * (*value)[1] / (double)180;
	(*value)[4] = cos((*value)[2]);
	(*value)[5] = sin((*value)[2]);
	(*value)[6] = tan((*value)[2]);
	(*value)[7] = cos((*value)[3]);
}

int				ft_check_collision(t_mlx *e, double angle, size_t d_collision)
{
	double	value[8];
	int		wall;
	double	int_coord[2];

	wall = 0;
	ft_set_value(angle + (FOV / 2), FOV / 2, &value);
	if (ft_select_ray(e, value, &wall, &int_coord) > d_collision)
	{
		ft_set_value(angle, 0, &value);
		if (ft_select_ray(e, value, &wall, &int_coord) > d_collision)
		{
			ft_set_value(angle - (FOV / 2), -FOV / 2, &value);
			if (ft_select_ray(e, value, &wall, &int_coord) > d_collision)
				return (1);
			return (0);
		}
		return (0);
	}
	else
		return (0);
}
