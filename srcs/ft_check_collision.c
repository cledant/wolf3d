/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:26:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/07 23:02:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_collision(t_mlx *e, double angle)
{
	double	value[2];
	double	dist;

	value[0] = angle + FOV / 2;
	value [1] = FOV / 2;
	if (ft_select_ray(e, value, e->x_player, e->y_player) > 10)
				return (1);
	else
		return (0);
}
