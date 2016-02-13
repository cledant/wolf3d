/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:54:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 14:59:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_load_texture(t_mlx *e)
{
	int		width;
	int		length;

	width = C_SIZE;
	length = C_SIZE;
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
	if ((e->img_brown20 = mlx_xpm_file_to_image(e->mlx,
			"./textures/brown20.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_cobblestone = mlx_xpm_file_to_image(e->mlx,
			"./textures/cobblestone.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_diamondred = mlx_xpm_file_to_image(e->mlx,
			"./textures/diamondred.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_patternbrown = mlx_xpm_file_to_image(e->mlx,
			"./textures/patternbrown.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_woodherring2 = mlx_xpm_file_to_image(e->mlx,
			"./textures/woodherring2.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_woodrough = mlx_xpm_file_to_image(e->mlx,
			"./textures/woodrough.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_redgreycheck2 = mlx_xpm_file_to_image(e->mlx,
			"./textures/redgreycheck2.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_greygreencheck = mlx_xpm_file_to_image(e->mlx,
			"./textures/greygreencheck.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_hexbrown = mlx_xpm_file_to_image(e->mlx,
			"./textures/hexbrown.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_c1 = mlx_xpm_file_to_image(e->mlx,
			"./textures/c1.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_c2 = mlx_xpm_file_to_image(e->mlx,
			"./textures/c2.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_c3 = mlx_xpm_file_to_image(e->mlx,
			"./textures/c3.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_c4 = mlx_xpm_file_to_image(e->mlx,
			"./textures/c4.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	if ((e->img_c5 = mlx_xpm_file_to_image(e->mlx,
			"./textures/c5.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	return (1);
}
