/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:08:03 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 18:57:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_set_val(t_mlx *e, int (*player)[2], double alpha[8],
				double (*first_int)[2])
{
	(*player)[0] = e->x_player;
	(*player)[1] = e->y_player;
	if (ft_what_faces_ray(alpha[0]) == 1)
		(*first_int)[1] = ((((*player)[1] / C_SIZE) * C_SIZE) - 0.1);
	else
		(*first_int)[1] = ((((*player)[1] / C_SIZE) * C_SIZE) + C_SIZE);
	(*first_int)[0] = (*player)[0] + (((*player)[1] -
					(*first_int)[1]) / alpha[6]);
	if (alpha[0] == -180)
		(*first_int)[0] = -(*first_int)[0];
}

double		ft_horizontal_intersection(t_mlx *e, double alpha[8],
				int *wall_type, double (*int_coord)[2])
{
	int			player[2];
	double		first_int[2];
	double		inc[2];

	ft_set_val(e, &player, alpha, &first_int);
	if (ft_what_faces_ray(alpha[0]) == 1)
		inc[1] = -C_SIZE;
	else
		inc[1] = C_SIZE;
	inc[0] = fabs(C_SIZE / alpha[6]);
	if (ft_what_faces_ray_for_verti(alpha[0]) == -1)
		inc[0] = -inc[0];
	while (ft_check_wall(e, first_int[0], first_int[1]) == -1)
	{
		first_int[0] += (inc[0]);
		first_int[1] += (inc[1]);
	}
	if (first_int[0] > C_SIZE * (e->x_max - 1))
		first_int[0] = C_SIZE * (e->x_max - 1);
	if (first_int[0] < 0)
		first_int[0] = 0;
	*wall_type = e->tab[(int)first_int[1] / 64][(int)first_int[0] / 64];
	(*int_coord)[0] = first_int[1];
	(*int_coord)[1] = first_int[0];
	return (ft_ray_lenght(player, first_int, alpha));
}
