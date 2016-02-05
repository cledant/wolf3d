/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:56:45 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 12:26:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_image(t_mlx *e)
{
	size_t	i;
	int		begin[2];
	int		end[2];
	size_t	w_height;
	size_t	offset;
	double	alpha;

	i = 0;
	alpha = e->alpha + 30;
	while (i < WIN_X)
	{
		if (i != 0)
			alpha -= e->inc_alpha;
		ft_putendl("COLUMN");
		ft_putnbrendl(i);
		printf("ALPHA = : %f\n", alpha);
		w_height = ft_wall_height(e, alpha);
		offset = (WIN_Y - w_height) / 2;
//		ft_putendl("W_HEIGHT :");
//		ft_putnbrendl(w_height);
//		ft_putendl("OFFSET :");
//		ft_putnbrendl(offset);
		begin[0] = (int)i;
		begin[1] = 0;
		end[0] = (int)i;
		end[1] = (int)(offset - 1);
		ft_mlx_i_drawline(e->img, begin, end, 0x000000FF);
		begin[1] = (int)offset;
		end[1] = (int)(offset + w_height - 1);
		ft_mlx_i_drawline(e->img, begin, end, 0x00CD4F39);
		begin[1] = (int)(offset + w_height);
		end[1] = WIN_Y - 1;
		ft_mlx_i_drawline(e->img, begin, end, 0x0000FF00);
		i++;
	}
}
