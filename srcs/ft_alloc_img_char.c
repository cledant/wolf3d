/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_img_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:25:36 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 17:40:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_alloc_img_char(t_mlx *e)
{
	int		endian;
	int		bpp;
	int		sizeline;

	e->char_img = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	e->redbrick = mlx_get_data_addr(e->img_redbrick, &bpp, &sizeline, &endian);
	e->wood = mlx_get_data_addr(e->img_wood, &bpp, &sizeline, &endian);
	e->brown20 = mlx_get_data_addr(e->img_brown20, &bpp, &sizeline, &endian);
	e->cobblestone = mlx_get_data_addr(e->img_cobblestone, &bpp, &sizeline,
			&endian);
	e->diamondred = mlx_get_data_addr(e->img_diamondred, &bpp, &sizeline,
			&endian);
	e->patternbrown = mlx_get_data_addr(e->img_patternbrown, &bpp,
			&sizeline, &endian);
	e->woodherring2 = mlx_get_data_addr(e->img_woodherring2, &bpp,
			&sizeline, &endian);
	e->woodrough = mlx_get_data_addr(e->img_woodrough, &bpp, &sizeline,
			&endian);
	e->redgreycheck2 = mlx_get_data_addr(e->img_redgreycheck2, &bpp,
			&sizeline, &endian);
	e->greygreencheck = mlx_get_data_addr(e->img_greygreencheck, &bpp,
			&sizeline, &endian);
	e->hexbrown = mlx_get_data_addr(e->img_hexbrown, &bpp, &sizeline, &endian);
	e->c1 = mlx_get_data_addr(e->img_c1, &bpp, &sizeline, &endian);
	e->c2 = mlx_get_data_addr(e->img_c2, &bpp, &sizeline, &endian);
}
