/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:28:43 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 13:53:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_ceiling(t_mlx *e, int disp_i_col, int begin, int end, int type,
			double angle[4])
{
	int		i;
	int		tex_coord[2];
	int		draw_coord[2];
	double	coord[2];
	double	dist;

	i = 0;
	while (i <= (end - begin))
	{
		dist = e->dist_to_proj_plane * (C_SIZE / 2) / (-(begin + i + 2) + (WIN_Y / 2));
		dist = dist / cos(angle[3]);
		coord[0] = e->x_player + dist * cos(angle[2]);
		coord[1] = e->y_player - dist * sin(angle[2]);
		type = e->tab[(int)coord[1] / C_SIZE][(int)coord[0] / C_SIZE];
		tex_coord[0]= (int)coord[0] % C_SIZE;
		tex_coord[1] = (int)coord[1] % C_SIZE;
		draw_coord[0] = disp_i_col; 
		draw_coord[1] = begin + i;
		if (type == 0)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->rooftiles4, draw_coord, tex_coord, WIN_X, C_SIZE);
//		else
//			ft_mlx_i_pixel_put(e->img, draw_coord[0], draw_coord[1], 0x00000000);
		i++;
	}
}
