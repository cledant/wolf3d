/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_img_char_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:27 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 17:23:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_alloc_img_char_2(t_mlx *e)
{
	int		endian;
	int		bpp;
	int		sizeline;

	e->c3 = mlx_get_data_addr(e->img_c3, &bpp, &sizeline, &endian);
	e->c4 = mlx_get_data_addr(e->img_c4, &bpp, &sizeline, &endian);
	e->c5 = mlx_get_data_addr(e->img_c5, &bpp, &sizeline, &endian);
}
