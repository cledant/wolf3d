/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_texture_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:37:42 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 17:38:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_clear_texture_2(t_mlx *e)
{
	if (e->img_c2 != NULL)
		mlx_destroy_image(e->mlx, e->img_c2);
	if (e->img_c3 != NULL)
		mlx_destroy_image(e->mlx, e->img_c3);
	if (e->img_c4 != NULL)
		mlx_destroy_image(e->mlx, e->img_c4);
	if (e->img_c5 != NULL)
		mlx_destroy_image(e->mlx, e->img_c5);
}
