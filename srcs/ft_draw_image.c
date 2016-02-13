/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:56:45 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 12:34:31 by cledant          ###   ########.fr       */
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
	double	angle[4];
	int 	wall_type;
	double	int_coord[2];
	int 	overflow;

	wall_type = 0;
	i = 0;
	angle[0] = e->alpha + 30;
	angle[1] = FOV / 2;
	while (i < WIN_X)
	{
//		printf("===========COLUMN==========\n");
//		printf("%d\n", i);
		overflow = 0;
		if (i != 0)
		{
			angle[0] -= e->inc_alpha;
			angle[1] -= e->inc_alpha;
		}
		if (angle[0] >= 360)
			angle[0] = angle[0] - 360;
		if (angle[0] <= -360)
			angle[0] = angle[0] + 360;
		angle[2] = ((M_PI * angle[0]) / (double)180);
		angle[3] = ((M_PI * angle[1]) / (double)180);
		w_height = C_SIZE * e->dist_to_proj_plane / ft_select_ray(e, angle,
				&wall_type, &int_coord);
//		printf("WALL HEIGHT : %zu\n",w_height);
//		printf("WALL TYPE = %d\n", wall_type);
//		printf("INTER X = %f\n", int_coord[0]);
//		printf("INTER Y = %f\n", int_coord[1]);
		offset = (WIN_Y - w_height) / 2;
		if (offset < 0)
			offset = 0;
		if (w_height > WIN_Y)
		{
			overflow = w_height - WIN_Y;
			w_height = WIN_Y;
		}
		if (w_height < WIN_Y)
		{
			begin[0] = 0;
			end[0] = (int)(offset);
			begin[1] = (int)(offset + w_height - 1);
			end[1] = WIN_Y - 1;
			ft_draw_ceiling_floor(e, i, begin, end, angle);
			begin[1] = (int)offset;
			end[1] = (int)(offset + w_height - 1);
			ft_draw_texture(e, i, begin[1], end[1], wall_type, int_coord, overflow);
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
