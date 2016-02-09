/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 19:25:33 by cledant           #+#    #+#             */
/*   Updated: 2016/02/09 19:43:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_clear_texture(t_mlx *e)
{
	if (e->img_bluestone != NULL)
		mlx_destroy_image(e->mlx, e->img_bluestone);
	if (e->img_redbrick != NULL)
		mlx_destroy_image(e->mlx, e->img_redbrick);
	if (e->img_wood != NULL)
		mlx_destroy_image(e->mlx, e->img_wood);
}
