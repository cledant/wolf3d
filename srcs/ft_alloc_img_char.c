/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_img_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:25:36 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 13:52:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_alloc_img_char(t_mlx *e)
{
	int		endian;
	int		bpp;
	int		sizeline;

	e->char_img = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	e->bluestone = mlx_get_data_addr(e->img_bluestone, &bpp, &sizeline, &endian);
	e->redbrick = mlx_get_data_addr(e->img_redbrick, &bpp, &sizeline, &endian);
	e->wood = mlx_get_data_addr(e->img_wood, &bpp, &sizeline, &endian);
	e->d_fawn = mlx_get_data_addr(e->img_d_fawn, &bpp, &sizeline, &endian);
	e->rooftiles4 = mlx_get_data_addr(e->img_rooftiles4, &bpp, &sizeline, &endian);
}
