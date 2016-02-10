/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 11:30:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/10 20:11:43 by cledant          ###   ########.fr       */
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
			tex_coord[1] = (((i + overflow / 2) * C_SIZE)) / (end - begin + overflow);
		draw_coord[0] = disp_i_col; 
		draw_coord[1] = begin + i;
		if (type == 3)
			ft_mlx_i_to_i_cpy_pixel(e->img, e->img_bluestone, draw_coord, tex_coord);
		else if (type == 2)
			ft_mlx_i_to_i_cpy_pixel(e->img, e->img_redbrick, draw_coord, tex_coord);
		else if (type == 4)
			ft_mlx_i_to_i_cpy_pixel(e->img, e->img_wood, draw_coord, tex_coord);
		else if (type == 0)
			ft_mlx_i_to_i_cpy_pixel(e->img, e->img_d_fawn, draw_coord, tex_coord);
		i++;
	}
}
