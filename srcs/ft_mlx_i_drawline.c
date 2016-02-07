/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_drawline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 12:12:28 by cledant           #+#    #+#             */
/*   Updated: 2016/02/03 12:11:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_case1(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (dx > 0 && dy > 0)
	{
		if (dx >= dy)
			ft_mlx_i_draw_diag1_line(e, p1, p2, color);
		else
			ft_mlx_i_draw_diag2_line(e, p1, p2, color);
	}
	if (dx > 0 && dy < 0)
	{
		if (dx >= -dy)
			ft_mlx_i_draw_diag8_line(e, p1, p2, color);
		else
			ft_mlx_i_draw_diag7_line(e, p1, p2, color);
	}
}

static void	ft_case2(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (dx < 0 && dy > 0)
	{
		if (-dx >= dy)
			ft_mlx_i_draw_diag4_line(e, p1, p2, color);
		else
			ft_mlx_i_draw_diag3_line(e, p1, p2, color);
	}
	if (dx < 0 && dy < 0)
	{
		if (-dx >= -dy)
			ft_mlx_i_draw_diag5_line(e, p1, p2, color);
		else
			ft_mlx_i_draw_diag6_line(e, p1, p2, color);
	}
}

int			ft_mlx_i_drawline(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (dx != 0)
	{
		if (dy != 0)
		{
			ft_case1(e, p1, p2, color);
			ft_case2(e, p1, p2, color);
		}
		else
			ft_mlx_i_draw_hori_line(e, p1, p2, color);
	}
	else
		ft_mlx_i_draw_verti_line(e, p1, p2, color);
	return (0);
}
