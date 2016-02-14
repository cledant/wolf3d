/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_c_to_c_cpy_pixel.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:41:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/14 12:12:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_mlx_c_to_c_cpy_pixel(char *dest_i, char *src_i, int coord[2][2],
			int sizeline[2])
{
	char	*d_pos;
	char	*s_pos;

	d_pos = dest_i + coord[0][0] * 4 + coord[0][1] * (sizeline[0] * 4);
	s_pos = src_i + coord[1][0] * 4 + coord[1][1] * (sizeline[1] * 4);
	ft_memcpy(d_pos, s_pos, sizeof(int));
}
