/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:30:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 13:13:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			ft_what_to_draw(t_mlx *e, int cpy_coord[2][2], int type)
{
	int		size[2];

	size[0] = WIN_X;
	size[1] = C_SIZE;
	if (type == 1)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->redbrick, cpy_coord, size);
	else if (type == 2)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->wood, cpy_coord, size);
	else if (type == 3)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->brown20, cpy_coord, size);
	else if (type == 4)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->cobblestone, cpy_coord, size);
	else if (type == 5)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c1, cpy_coord, size);
	else if (type == 6)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c2, cpy_coord, size);
	else if (type == 7)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c3, cpy_coord, size);
	else if (type == 8)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c4, cpy_coord, size);
	else if (type == 9)
		ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c5, cpy_coord, size);
}


void				ft_draw_texture(t_mlx *e, int counter[4], int limit[2],
						double coord[2])
{
	int		i;
	int		cpy_coord[2][2];

	i = 0;
	cpy_coord[1][0]= (int)coord[1] % C_SIZE;
	while (i < (limit[1] - limit[0]))
	{
		if (counter[3] == 0)
			cpy_coord[1][1] = ((i * C_SIZE) / (limit[1] - limit[0]));
		else
			cpy_coord[1][1] = (((i + counter[3] / 2) * C_SIZE)) /
				(limit[1] - limit[0] + counter[3]);
		cpy_coord[0][0] = counter[0]; 
		cpy_coord[0][1] = limit[0] + i;
		ft_what_to_draw(e, cpy_coord, counter[1]);
		i++;
	}
}
