/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:11:50 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 17:12:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_free_all(t_mlx *e)
{
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	ft_memdel((void **)e->tab);
	free(e->mlx);
}
