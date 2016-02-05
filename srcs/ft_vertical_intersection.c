/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:41:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 17:43:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t			ft_vertical_intersection(t_mlx *e, double alpha, int player_x,
											int player_y)
{
	int			player[2];
	int			first_int[2];
	int			x_inc;
	int			y_inc;
	double		rad_alpha;

	rad_alpha = ft_angle_dec_to_rad(alpha);
	player[0] = 32 + 64 * player_x;
	player[1] = 32 + 64 * player_y;
	if (ft_what_faces_ray_for_verti(alpha) == 1)
		first_int[0] = (player[0] / C_SIZE * C_SIZE + C_SIZE);
	else
		first_int[0] = (player[0] / C_SIZE * C_SIZE - 1);
	first_int[1] = player[1] + ft_round_double(((player[0] -
					first_int[0]) * tan(rad_alpha)));
	ft_putnbrendl(first_int[0] / C_SIZE);
	ft_putnbrendl(first_int[1] / C_SIZE);
	if (ft_what_faces_ray_for_verti(alpha) == 1)
		x_inc = C_SIZE;
	else
		x_inc = -C_SIZE;
	printf("X_INC : %d\n", x_inc);
	y_inc = ft_abs(ft_round_double(C_SIZE * tan(rad_alpha)));
	if (ft_what_faces_ray(alpha) == 1)
		y_inc = -y_inc;
	printf("Y_INC : %d\n", y_inc);
	while (ft_check_wall(e, first_int[0], first_int[1]) == -1)
	{
		ft_putendl("TRY");
		first_int[0] += x_inc;
		first_int[1] += y_inc;
		ft_putnbrendl(first_int[0] / C_SIZE);
		ft_putnbrendl(first_int[1] / C_SIZE);
	}
	if (first_int[1] < 0)
		first_int[1] = 0;
	ft_putnbrendl(first_int[0] / C_SIZE);
	ft_putnbrendl(first_int[1] / C_SIZE);
	ft_putendl("FIN VERTI");
	return (ft_ray_lenght(player[0], first_int[0], rad_alpha));
}
