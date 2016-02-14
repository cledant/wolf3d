/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:59:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 17:55:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_select_ray(t_mlx *e, double angle[8], int *wall_type,
			double (*int_coord)[2])
{
	double	ray_hori;
	double	ray_verti;
	int		wall[2];
	double	int_h_coord[2];
	double	int_v_coord[2];

	ray_hori = ft_horizontal_intersection(e, angle, &(wall[0]), &int_h_coord);
	ray_verti = ft_vertical_intersection(e, angle, &(wall[1]), &int_v_coord);
	if (ray_hori <= ray_verti)
	{
		(*int_coord)[0] = int_h_coord[0];
		(*int_coord)[1] = int_h_coord[1];
		*wall_type = wall[0];
		return (ray_hori * angle[7]);
	}
	else
	{
		(*int_coord)[0] = int_v_coord[0];
		(*int_coord)[1] = int_v_coord[1];
		*wall_type = wall[1];
		return (ray_verti * angle[7]);
	}
}
