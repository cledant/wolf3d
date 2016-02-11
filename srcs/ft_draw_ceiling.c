/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:28:43 by cledant           #+#    #+#             */
/*   Updated: 2016/02/11 21:04:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_ceiling(t_mlx *e, int disp_i_col, int begin, int end, int type,
			double angle[2])
{
	int		i;
	int		tex_coord[2];
	int		draw_coord[2];
	double	coord[2];
	double	dist;

	i = 0;
	while (i <= (end - begin))
	{
//		ft_putendl("DEBUT I");
//		ft_putnbrendl(begin + i);
		dist = e->dist_to_proj_plane * (C_SIZE / 2) / (-(begin + i + 2) + (WIN_Y / 2));
		dist = dist / cos(ft_angle_dec_to_rad(angle[1]));
		coord[0] = e->x_player + dist * cos(ft_angle_dec_to_rad(angle[0]));
		coord[1] = e->y_player - dist * sin(ft_angle_dec_to_rad(angle[0]));
//		printf("DIST = %f\n", dist);
//		ft_putnbrendl(coord[0]);
//		ft_putnbrendl(coord[1]);
		type = e->tab[(int)coord[1] / C_SIZE][(int)coord[0] / C_SIZE];
//		ft_putendl("TYPE====");
//		ft_putnbrendl(type);
//		ft_putendl("FIN I");
		tex_coord[0]= (int)coord[0] % C_SIZE;
		tex_coord[1] = (int)coord[1] % C_SIZE;
		draw_coord[0] = disp_i_col; 
		draw_coord[1] = begin + i;
		if (type == 0)
			ft_mlx_i_to_i_cpy_pixel(e->img, e->img_rooftiles4, draw_coord, tex_coord);
		else
			ft_mlx_i_pixel_put(e->img, draw_coord[0], draw_coord[1], 0x00000000);
		i++;
	}
}
