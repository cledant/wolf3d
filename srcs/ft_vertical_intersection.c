/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:41:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/10 15:35:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double			ft_vertical_intersection(t_mlx *e, double alpha, int *wall_type,
					double (*int_coord)[2])
{
	int			player[2];
	double		first_int[2];
	double		x_inc;
	double		y_inc;
	double		rad_alpha;

	if (alpha >= 360)
		alpha = alpha - 360;
	if (alpha <= -360)
		alpha = alpha + 360;
	rad_alpha = ft_angle_dec_to_rad(alpha);
	player[0] = e->x_player;
	player[1] = e->y_player;
	if (ft_what_faces_ray_for_verti(alpha) == 1)
		first_int[0] = (((player[0] / C_SIZE) * C_SIZE) + C_SIZE);
	else
		first_int[0] = (((player[0] / C_SIZE) * C_SIZE) - 0.1);
	first_int[1] = player[1] + (((player[0] -
					first_int[0]) * tan(rad_alpha)));
	if (alpha == -270 || alpha == 270)
		first_int[1] = -first_int[1];
//	ft_putnbrendl(first_int[0]);
//	ft_putnbrendl(first_int[1]);
//	ft_putnbrendl(first_int[0] / C_SIZE);
//	ft_putnbrendl(first_int[1] / C_SIZE);
	if (ft_what_faces_ray_for_verti(alpha) == 1)
		x_inc = C_SIZE;
	else
		x_inc = -C_SIZE;
//	printf("X_INC : %d\n", x_inc);
	y_inc = fabs((C_SIZE * tan(rad_alpha)));
	if (ft_what_faces_ray(alpha) == 1)
		y_inc = -y_inc;
//	printf("Y_INC : %d\n", y_inc);
	while (ft_check_wall(e, first_int[0], first_int[1]) == -1)
	{
//		ft_putendl("TRY");
		first_int[0] += (x_inc);
		first_int[1] += (y_inc);
//		ft_putnbrendl(first_int[0]);
//		ft_putnbrendl(first_int[1]);
//		ft_putnbrendl(first_int[0] / C_SIZE);
//		ft_putnbrendl(first_int[1] / C_SIZE);
	}
	if (first_int[1] < 0)
		first_int[1] = 0;
	if (first_int[1] > C_SIZE * (e->y_max - 1))
		first_int[1] =  C_SIZE * (e->y_max - 1);
	*wall_type = e->tab[(int)first_int[1] / 64][(int)first_int[0] / 64];
	(*int_coord)[0] = first_int[0];
	(*int_coord)[1] = first_int[1];
//	ft_putnbrendl(first_int[0]);
//	ft_putnbrendl(first_int[1]);
//	ft_putnbrendl(first_int[0] / C_SIZE);
//	ft_putnbrendl(first_int[1] / C_SIZE);
//	ft_putendl("FIN VERTI");
	return (ft_ray_lenght(player, first_int, rad_alpha, alpha));
}
