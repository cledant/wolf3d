/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:56:45 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 18:05:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	counter[4] = {i, wall_type, offset, overflow}
*/

static void		ft_assign_value_1(t_mlx *e, double (*angle)[8],
					int (*counter)[4])
{
	(*counter)[3] = 0;
	if ((*counter)[0] != 0)
	{
		(*angle)[0] -= e->inc_alpha;
		(*angle)[1] -= e->inc_alpha;
	}
	if ((*angle)[0] >= 360)
		(*angle)[0] = (*angle)[0] - 360;
	if ((*angle)[0] <= -360)
		(*angle)[0] = (*angle)[0] + 360;
	(*angle)[2] = ((M_PI * (*angle)[0]) / (double)180);
	(*angle)[3] = ((M_PI * (*angle)[1]) / (double)180);
	(*angle)[4] = cos((*angle)[2]);
	(*angle)[5] = sin((*angle)[2]);
	(*angle)[6] = tan((*angle)[2]);
	(*angle)[7] = cos((*angle)[3]);
}

static void		ft_assign_val_2(size_t *w_height, int (*counter)[4])
{
	(*counter)[2] = (WIN_Y - *w_height) / 2;
	if ((*counter)[2] < 0)
		(*counter)[2] = 0;
	if (*w_height > WIN_Y)
	{
		(*counter)[3] = *w_height - WIN_Y;
		*w_height = WIN_Y;
	}
}

static void		ft_draw_1(t_mlx *e, int counter[4], size_t w_height,
					double angle[8])
{
	int		limit[2][2];

	if (w_height < WIN_Y)
	{
		limit[0][0] = 0;
		limit[0][1] = counter[2];
		limit[1][0] = counter[2] + w_height - 1;
		limit[1][1] = WIN_Y - 1;
		ft_draw_ceiling_floor(e, counter[0], limit, angle);
	}
}

static void		ft_draw_2(t_mlx *e, int counter[4], size_t w_height,
					double int_coord[2])
{
	int		limit[2][2];

	if (w_height < WIN_Y)
	{
		limit[1][0] = counter[2] - 2;
		limit[1][1] = counter[2] + w_height + 1;
		ft_draw_texture(e, counter, limit[1], int_coord);
	}
	else
	{
		limit[1][0] = counter[2];
		limit[1][1] = (int)(w_height);
		ft_draw_texture(e, counter, limit[1], int_coord);
	}
}

void			ft_draw_image(t_mlx *e)
{
	int		counter[4];
	size_t	w_height;
	double	angle[8];
	double	int_coord[2];

	counter[0] = 0;
	counter[1] = 0;
	angle[0] = e->alpha + 30;
	angle[1] = FOV / 2;
	while (counter[0] < WIN_X)
	{
		ft_assign_value_1(e, &angle, &counter);
		w_height = C_SIZE * e->dist_to_proj_plane / ft_select_ray(e, angle,
				&(counter[1]), &int_coord);
		ft_assign_val_2(&w_height, &counter);
		ft_draw_1(e, counter, w_height, angle);
		ft_draw_2(e, counter, w_height, int_coord);
		(counter[0])++;
	}
}
