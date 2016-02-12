/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_c_to_c_cpy_pixel.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:41:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 14:15:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_mlx_c_to_c_cpy_pixel(char *dest_i, char *src_i, int d_coord[2],
			int s_coord[2], int d_sizeline, int s_sizeline)
{
	char	*d_pos;
	char	*s_pos;

	d_pos = dest_i + d_coord[0] * 4 + d_coord[1] * (d_sizeline * 4);
	s_pos = src_i + s_coord[0] * 4 + s_coord[1] * (s_sizeline * 4);
	ft_memcpy(d_pos, s_pos, sizeof(int));
}
