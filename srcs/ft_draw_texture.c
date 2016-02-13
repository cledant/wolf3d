/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:30:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 15:05:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_texture(t_mlx *e, int disp_i_col, int begin, int end, int type,
			double coord[2], int overflow)
{
	int		i;
	int		tex_coord[2];
	int		draw_coord[2];

	i = 0;
	tex_coord[0]= (int)coord[1] % C_SIZE;
	while (i < (end - begin))
	{
		if (overflow == 0)
			tex_coord[1] = ((i * C_SIZE) / (end - begin));
		else
			tex_coord[1] = (((i + overflow / 2) * C_SIZE)) /
				(end - begin + overflow);
		draw_coord[0] = disp_i_col; 
		draw_coord[1] = begin + i;
		if (type == 1)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->redbrick, draw_coord, tex_coord,WIN_X, C_SIZE);
		else if (type == 2)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->wood, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 3)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->brown20, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 4)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->cobblestone, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 5)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c1, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 6)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c2, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 7)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c3, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 8)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c4, draw_coord, tex_coord, WIN_X, C_SIZE);
		else if (type == 9)
			ft_mlx_c_to_c_cpy_pixel(e->char_img, e->c5, draw_coord, tex_coord, WIN_X, C_SIZE);
		i++;
	}
}
