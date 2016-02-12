/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_i_to_i_cpy_pixel.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:07:04 by cledant           #+#    #+#             */
/*   Updated: 2016/02/10 13:55:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_mlx_i_to_i_cpy_pixel(void *dest_i, void *src_i, int d_coord[2],
			int s_coord[2])
{
	char	*d_pos;
	char	*s_pos;

	d_pos = ft_mlx_i_position_in_2d(dest_i, d_coord[0], d_coord[1]);
	s_pos = ft_mlx_i_position_in_2d(src_i, s_coord[0], s_coord[1]);
	ft_memmove(d_pos, s_pos, sizeof(int));
}
