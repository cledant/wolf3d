/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 11:57:03 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 17:36:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_clear_texture(t_mlx *e)
{
	if (e->img_redbrick != NULL)
		mlx_destroy_image(e->mlx, e->img_redbrick);
	if (e->img_wood != NULL)
		mlx_destroy_image(e->mlx, e->img_wood);
	if (e->img_brown20 != NULL)
		mlx_destroy_image(e->mlx, e->img_brown20);
	if (e->img_cobblestone != NULL)
		mlx_destroy_image(e->mlx, e->img_cobblestone);
	if (e->img_diamondred != NULL)
		mlx_destroy_image(e->mlx, e->img_diamondred);
	if (e->img_patternbrown != NULL)
		mlx_destroy_image(e->mlx, e->img_patternbrown);
	if (e->img_woodherring2 != NULL)
		mlx_destroy_image(e->mlx, e->img_woodherring2);
	if (e->img_woodrough != NULL)
		mlx_destroy_image(e->mlx, e->img_woodrough);
	if (e->img_redgreycheck2 != NULL)
		mlx_destroy_image(e->mlx, e->img_redgreycheck2);
	if (e->img_greygreencheck != NULL)
		mlx_destroy_image(e->mlx, e->img_greygreencheck);
	if (e->img_hexbrown != NULL)
		mlx_destroy_image(e->mlx, e->img_hexbrown);
	if (e->img_c1 != NULL)
		mlx_destroy_image(e->mlx, e->img_c1);
	ft_clear_texture_2(e);
}
