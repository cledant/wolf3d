/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:08:03 by cledant           #+#    #+#             */
/*   Updated: 2016/02/08 14:30:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		ft_horizontal_intersection(t_mlx *e, double alpha, int player_x,
											int player_y)
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
	player[0] = player_x;
	player[1] = player_y;
	if (ft_what_faces_ray(alpha) == 1)
		first_int[1] = (((player[1] / C_SIZE) * C_SIZE) - 0.1);
	else
		first_int[1] = (((player[1] / C_SIZE) * C_SIZE) + C_SIZE);
	first_int[0] = player[0] + (((player[1] -
					first_int[1]) / tan(rad_alpha)));
	if (alpha == -180)
		first_int[0] = -first_int[0];
//	ft_putnbrendl(first_int[0]);
//	ft_putnbrendl(first_int[1]);
//	ft_putnbrendl(first_int[0] / C_SIZE);
//	ft_putnbrendl(first_int[1] / C_SIZE);
	if (ft_what_faces_ray(alpha) == 1)
		y_inc = -C_SIZE;
	else
		y_inc = C_SIZE;
//	printf("Y_INC : %d\n", y_inc);
	x_inc = fabs((C_SIZE / tan(rad_alpha)));
	if (ft_what_faces_ray_for_verti(alpha) == -1)
		x_inc = -x_inc;
//	printf("X_INC : %d\n", x_inc);
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
	if (first_int[0] > C_SIZE * (e->x_max - 1))
		first_int[0] = C_SIZE * (e->x_max - 1);
	if (first_int[0] < 0)
		first_int[0] = 0;
//	ft_putnbrendl(first_int[0]);
//	ft_putnbrendl(first_int[1]);
//	ft_putnbrendl(first_int[0] / C_SIZE);
//	ft_putnbrendl(first_int[1] / C_SIZE);
//	ft_putendl("FIN HORI");
	return (ft_ray_lenght(player, first_int, rad_alpha, alpha));
}
