/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:11:53 by cledant           #+#    #+#             */
/*   Updated: 2016/02/07 22:54:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t		ft_wall_height(t_mlx *e, double angle[2])
{
	double	ray_lenght;
	size_t	w_height;

	ray_lenght = ft_select_ray(e, angle, e->x_player, e->y_player);
//	ft_putendl("BWAAAA");
	w_height = C_SIZE * e->dist_to_proj_plane / ray_lenght;
//	ft_putendl("J ai soif");
	return (w_height);
}
