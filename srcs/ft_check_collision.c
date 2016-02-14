/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:26:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 17:33:54 by cledant          ###   ########.fr       */
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

static void		ft_what_to_add(t_mlx *e, int keycode)
{
	if (keycode == MLX_KEY_RIGHT)
	{
		e->x_player = e->x_player + e->sin_rad_alpha * e->speed;
		e->y_player = e->y_player + e->cos_rad_alpha * e->speed;
	}
	else if (keycode == MLX_KEY_LEFT)
	{
		e->x_player = e->x_player - e->sin_rad_alpha * e->speed;
		e->y_player = e->y_player - e->cos_rad_alpha * e->speed;
	}
	else if (keycode == MLX_KEY_UP)
	{
		e->x_player = e->x_player + e->cos_rad_alpha * e->speed;
		e->y_player = e->y_player - e->sin_rad_alpha * e->speed;
	}
	else if (keycode == MLX_KEY_DOWN)
	{
		e->x_player = e->x_player - e->cos_rad_alpha * e->speed;
		e->y_player = e->y_player + e->sin_rad_alpha * e->speed;
	}
}

int				ft_check_collision(t_mlx *e, double angle, size_t d_collision,
					int keycode)
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
			{
				ft_what_to_add(e, keycode);
				return (1);
			}
			return (0);
		}
		return (0);
	}
	else
		return (0);
}
