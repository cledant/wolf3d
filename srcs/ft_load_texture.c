/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:54:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/10 20:12:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_load_texture(t_mlx *e)
{
	int		width;
	int		length;

	width = C_SIZE;
	length = C_SIZE;
	if ((e->img_bluestone = mlx_xpm_file_to_image(e->mlx,
			"./textures/bluestone.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_redbrick = mlx_xpm_file_to_image(e->mlx,
			"./textures/redbrick.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_wood = mlx_xpm_file_to_image(e->mlx,
			"./textures/wood.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_d_fawn = mlx_xpm_file_to_image(e->mlx,
			"./textures/diamondfawn.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_rooftiles4 = mlx_xpm_file_to_image(e->mlx,
			"./textures/rooftiles4.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	return (1);
}
