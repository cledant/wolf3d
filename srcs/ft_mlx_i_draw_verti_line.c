/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_verti_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:11:07 by cledant           #+#    #+#             */
/*   Updated: 2016/02/03 11:42:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_mlx_i_draw_verti_line(void *e, int *p1, int *p2, int color)
{
	if (p2[1] - p1[1] > 0)
	{
		while (p1[1] < p2[1])
		{
			ft_mlx_i_pixel_put(e, p1[0], p1[1], color);
			p1[1]++;
		}
		ft_mlx_i_pixel_put(e, p2[0], p2[1], color);
	}
	else
	{
		while (p1[1] > p2[1])
		{
			ft_mlx_i_pixel_put(e, p1[0], p1[1], color);
			p1[1]--;
		}
		ft_mlx_i_pixel_put(e, p2[0], p2[1], color);
	}
}
