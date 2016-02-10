/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:11:53 by cledant           #+#    #+#             */
/*   Updated: 2016/02/10 13:43:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t		ft_wall_height(t_mlx *e, double angle[2], int *wall_type,
				double (*int_coord)[2])
{
	double	ray_lenght;
	size_t	w_height;

	ray_lenght = ft_select_ray(e, angle, wall_type, int_coord);
//	ft_putendl("BWAAAA");
	w_height = C_SIZE * e->dist_to_proj_plane / ray_lenght;
//	ft_putendl("J ai soif");
	return (w_height);
}
