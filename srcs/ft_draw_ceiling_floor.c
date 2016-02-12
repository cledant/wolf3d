/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:42:46 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 19:18:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_ceiling_floor(t_mlx *e, int disp_i_col, int begin[2],
			int end[2], int type, double angle[4])
{
	int		i;
	int		tex_coord[2][2];
	int		draw_coord[2][2];
	double	coord[4];
	double	dist[2];
	double	tmp[3];

	tmp[0] = cos(angle[2]);
	tmp[1] = sin(angle[2]);
	tmp[2] = cos(angle[3]);
	i = 0;
	while (i <= (end[0] - begin[0]))
	{
		dist[0] = e->dist_to_proj_plane * (C_SIZE / 2) / (-(begin[0] + i) + (WIN_Y / 2));
		dist[0] = dist[0] / tmp[2];
		dist[1] = e->dist_to_proj_plane * (C_SIZE / 2) / ((begin[1] + i) - (WIN_Y / 2));
		dist[1] = dist[1] / tmp[2];
		coord[0] = e->x_player + dist[0] * tmp[0];
		coord[1] = e->y_player - dist[0] * tmp[1];
		coord[2] = e->x_player + dist[1] * tmp[0];
		coord[3] = e->y_player - dist[1] * tmp[1];
		type = e->tab[(int)coord[1] / C_SIZE][(int)coord[0] / C_SIZE];
		tex_coord[0][0]= (int)coord[0] % C_SIZE;
		tex_coord[0][1] = (int)coord[1] % C_SIZE;
		draw_coord[0][0] = disp_i_col; 
		draw_coord[0][1] = begin[0] + i;
		tex_coord[1][0]= (int)coord[2] % C_SIZE;
		tex_coord[1][1] = (int)coord[3] % C_SIZE;
		draw_coord[1][0] = disp_i_col; 
		draw_coord[1][1] = begin[1] + i;
		if (type / 20 == 1)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->rooftiles4, draw_coord[0],
					tex_coord[0], WIN_X, C_SIZE);
		if (type % 20 == 0)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->d_fawn, draw_coord[1],
					tex_coord[1], WIN_X, C_SIZE);
		i++;
	}
}
