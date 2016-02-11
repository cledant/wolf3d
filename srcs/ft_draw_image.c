/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:56:45 by cledant           #+#    #+#             */
/*   Updated: 2016/02/11 21:04:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_image(t_mlx *e)
{
	int		i;
	int		begin[2];
	int		end[2];
	size_t	w_height;
	int		offset;
	double	angle[2];
	int 	wall_type;
	double	int_coord[2];
	int 	overflow;

	wall_type = 0;
	i = 0;
	angle[0] = e->alpha + 30;
	angle[1] = FOV / 2;
	while (i < WIN_X)
	{
		overflow = 0;
		if (i != 0)
		{
			angle[0] -= e->inc_alpha;
			angle[1] -= e->inc_alpha;
		}
//		ft_putendl("COLUMN=======================================");
//		ft_putnbrendl(i);
//		printf("ALPHA = : %f\n", angle[0]);
		w_height = ft_wall_height(e, angle, &wall_type, &int_coord);
		offset = (WIN_Y - w_height) / 2;
		if (offset < 0)
			offset = 0;
		if (w_height > WIN_Y)
		{
			overflow = w_height - WIN_Y;
			w_height = WIN_Y;
		}
//		ft_putendl("W_HEIGHT :");
//		ft_putnbrendl(w_height);
//		ft_putendl("OFFSET :");
//		ft_putnbrendl(offset);
		begin[0] = (int)i;
		end[0] = (int)i;
		if (w_height < WIN_Y)
		{
			begin[1] = 0;
			end[1] = (int)(offset);
			ft_draw_ceiling(e, i, begin[1], end[1], 0, angle);
			begin[1] = (int)offset;
			end[1] = (int)(offset + w_height - 1);
			ft_draw_texture(e, i, begin[1], end[1], wall_type, int_coord, overflow);
			begin[1] = (int)(offset + w_height - 1);
			end[1] = WIN_Y - 1;
			ft_draw_floor(e, i, begin[1], end[1], 0, angle);
		}
		else
		{
			begin[1] = (int)offset;
			end[1] = (int)(w_height);
			ft_draw_texture(e, i, begin[1], end[1], wall_type, int_coord, overflow);
		}
		i++;
	}
}
