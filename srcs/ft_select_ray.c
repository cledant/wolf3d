/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:59:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/06 20:06:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_select_ray(t_mlx *e, double angle[2], int player_x, int player_y)
{
	double	ray_hori;
	double	ray_verti;
	double	rad_beta;
	
	rad_beta = cos(ft_angle_dec_to_rad(angle[1]));
//	ft_putendl("HORI");
	ray_hori = ft_horizontal_intersection(e, angle[0], player_x, player_y);
//	ft_putendl("VERTI");
	ray_verti = ft_vertical_intersection(e, angle[0], player_x, player_y);
//	ft_putendl("CHOICE");
//	ft_putnbrendl(ray_hori);
//	ft_putnbrendl(ray_verti);
//	ft_putendl("END CHOICE");
	if (ray_hori <= ray_verti)
		return (ray_hori * rad_beta);
	else
		return (ray_verti * rad_beta);
}
