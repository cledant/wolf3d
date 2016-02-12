/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:59:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 16:22:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_select_ray(t_mlx *e, double angle[4], int *wall_type,
			double (*int_coord)[2])
{
	double	ray_hori;
	double	ray_verti;
	int		w_hori;
	int		w_verti;
	double	int_h_coord[2];
	double	int_v_coord[2];

	ray_hori = ft_horizontal_intersection(e, angle, &w_hori, &int_h_coord);
	ray_verti = ft_vertical_intersection(e, angle, &w_verti, &int_v_coord);
	if (ray_hori <= ray_verti)
	{
		(*int_coord)[0] = int_h_coord[0];
		(*int_coord)[1] = int_h_coord[1];
		*wall_type = w_hori;
		return (ray_hori * cos(angle[3]));
	}
	else
	{
		(*int_coord)[0] = int_v_coord[0];
		(*int_coord)[1] = int_v_coord[1];
		*wall_type = w_verti;
		return (ray_verti * cos(angle[3]));
	}
}
