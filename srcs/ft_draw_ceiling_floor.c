/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:42:46 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 18:06:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			ft_what_to_draw(t_mlx *e, int cpy_coord[2][2][2],
						int type[2])
{
	int		size[2];

	size[0] = WIN_X;
	size[1] = C_SIZE;
	if (type[0] / 20 == 1)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->redgreycheck2, cpy_coord[0],
			size);
	else if (type[0] / 20 == 2)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->greygreencheck, cpy_coord[0],
			size);
	else if (type[0] / 20 == 3)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->hexbrown, cpy_coord[0],
			size);
	if (type[1] % 20 == 0)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->diamondred, cpy_coord[1],
			size);
	else if (type[1] % 20 == 1)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->patternbrown, cpy_coord[1],
			size);
	else if (type[1] % 20 == 2)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->woodherring2, cpy_coord[1],
			size);
	else if (type[1] % 20 == 3)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->woodrough, cpy_coord[1],
			size);
}

static void			ft_set_cpy_coord(int counter[2], int (*cpy_coord)[2][2][2],
						int limit[2][2], double coord[4])
{
	(*cpy_coord)[0][1][0] = (int)coord[0] % C_SIZE;
	(*cpy_coord)[0][1][1] = (int)coord[1] % C_SIZE;
	(*cpy_coord)[0][0][0] = counter[1];
	(*cpy_coord)[0][0][1] = limit[0][0] + counter[0];
	(*cpy_coord)[1][1][0] = (int)coord[2] % C_SIZE;
	(*cpy_coord)[1][1][1] = (int)coord[3] % C_SIZE;
	(*cpy_coord)[1][0][0] = counter[1];
	(*cpy_coord)[1][0][1] = limit[1][0] + counter[0];
}

void				ft_draw_ceiling_floor(t_mlx *e, int disp_i_col,
						int limit[2][2], double angle[8])
{
	int		counter[2];
	int		type[2];
	int		cpy_coord[2][2][2];
	double	coord[4];
	double	dist[2];

	counter[0] = 0;
	counter[1] = disp_i_col;
	while (counter[0] <= (limit[0][1] - limit[0][0]))
	{
		dist[0] = (e->dist_to_proj_plane * (C_SIZE / 2) / (-(limit[0][0] +
			counter[0]) + (WIN_Y / 2))) / angle[7];
		dist[1] = (e->dist_to_proj_plane * (C_SIZE / 2) / ((limit[1][0] +
			counter[0]) - (WIN_Y / 2))) / angle[7];
		coord[0] = e->x_player + dist[0] * angle[4];
		coord[1] = e->y_player - dist[0] * angle[5];
		coord[2] = e->x_player + dist[1] * angle[4];
		coord[3] = e->y_player - dist[1] * angle[5];
		type[0] = e->tab[(int)coord[1] / C_SIZE][(int)coord[0] / C_SIZE];
		type[1] = e->tab[(int)coord[3] / C_SIZE][(int)coord[2] / C_SIZE];
		ft_set_cpy_coord(counter, &cpy_coord, limit, coord);
		ft_what_to_draw(e, cpy_coord, type);
		(counter[0])++;
	}
}
