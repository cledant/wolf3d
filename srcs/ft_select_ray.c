/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:59:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/10 13:43:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_select_ray(t_mlx *e, double angle[2], int *wall_type,
			double (*int_coord)[2])
{
	double	ray_hori;
	double	ray_verti;
	double	rad_beta;
	int		w_hori;
	int		w_verti;
	double	int_h_coord[2];
	double	int_v_coord[2];

	rad_beta = cos(ft_angle_dec_to_rad(angle[1]));
//	ft_putendl("HORI");
	ray_hori = ft_horizontal_intersection(e, angle[0], &w_hori, &int_h_coord);
//	ft_putendl("VERTI");
	ray_verti = ft_vertical_intersection(e, angle[0], &w_verti, &int_v_coord);
//	ft_putendl("CHOICE");
//	ft_putnbrendl(ray_hori);
//	ft_putnbrendl(ray_verti);
//	ft_putendl("END CHOICE");
	if (ray_hori <= ray_verti)
	{
		(*int_coord)[0] = int_h_coord[0];
		(*int_coord)[1] = int_h_coord[1];
		*wall_type = w_hori;
		return (ray_hori * rad_beta);
	}
	else
	{
		(*int_coord)[0] = int_v_coord[0];
		(*int_coord)[1] = int_v_coord[1];
		*wall_type = w_verti;
		return (ray_verti * rad_beta);
	}
}
