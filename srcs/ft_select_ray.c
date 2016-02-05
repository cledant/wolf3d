/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:59:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 18:29:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t		ft_select_ray(t_mlx *e, double alpha, int player_x, int player_y)
{
	size_t	ray_hori;
	size_t	ray_verti;
	
	ft_putendl("HORI");
	ray_hori = ft_horizontal_intersection(e, alpha, player_x, player_y);
	ft_putendl("VERTI");
	ray_verti = ft_vertical_intersection(e, alpha, player_x, player_y);
	ft_putendl("CHOICE");
	ft_putnbrendl(ray_hori);
	ft_putnbrendl(ray_verti);
	ft_putendl("END CHOICE");
	if (ray_hori < ray_verti)
		return (ray_hori);
	else
		return (ray_verti);
}
