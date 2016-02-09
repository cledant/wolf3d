/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:54:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/09 20:20:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_load_texture(t_mlx *e)
{
	int		width;
	int		length;

	width = 1000;
	length = 1000;
	ft_putendl("ici");
	if ((e->img_bluestone = mlx_xpm_file_to_image(e->mlx,
			"./textures/bluestone.xpm", &width, &length)) == NULL)
	{
		return (0);
	}
	ft_putendl("coucou");
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
	return (1);
}
