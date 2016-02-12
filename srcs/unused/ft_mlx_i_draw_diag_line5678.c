/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_draw_diag_line5678.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:04:07 by cledant           #+#    #+#             */
/*   Updated: 2016/02/03 12:12:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_mlx_i_draw_diag5_line(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = dx;
	dx = -dx * 2;
	dy = -dy * 2;
	while (p1[0] > p2[0])
	{
		ft_mlx_i_pixel_put(e, p1[0], p1[1], color);
		epsi = epsi - dy;
		if (epsi < 0)
		{
			p1[1]--;
			epsi = epsi + dx;
		}
		p1[0]--;
	}
	ft_mlx_i_pixel_put(e, p2[0], p2[1], color);
}

void		ft_mlx_i_draw_diag6_line(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = dy;
	dx = -dx * 2;
	dy = -dy * 2;
	while (p1[1] > p2[1])
	{
		ft_mlx_i_pixel_put(e, p1[0], p1[1], color);
		epsi = epsi - dx;
		if (epsi < 0)
		{
			p1[0]--;
			epsi = epsi + dy;
		}
		p1[1]--;
	}
	ft_mlx_i_pixel_put(e, p2[0], p2[1], color);
}

void		ft_mlx_i_draw_diag7_line(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = -dy;
	dx = dx * 2;
	dy = -dy * 2;
	while (p1[1] > p2[1])
	{
		ft_mlx_i_pixel_put(e, p1[0], p1[1], color);
		epsi = epsi - dx;
		if (epsi < 0)
		{
			p1[0]++;
			epsi = epsi + dy;
		}
		p1[1]--;
	}
	ft_mlx_i_pixel_put(e, p2[0], p2[1], color);
}

void		ft_mlx_i_draw_diag8_line(void *e, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		epsi;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	epsi = dx;
	dx = dx * 2;
	dy = -dy * 2;
	while (p1[0] < p2[0])
	{
		ft_mlx_i_pixel_put(e, p1[0], p1[1], color);
		epsi = epsi - dy;
		if (epsi < 0)
		{
			p1[1]--;
			epsi = epsi + dx;
		}
		p1[0]++;
	}
	ft_mlx_i_pixel_put(e, p2[0], p2[1], color);
}
