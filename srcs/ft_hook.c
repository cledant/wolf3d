/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:27:39 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 19:42:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_mlx *e)
{
	if (e->render != 1)
	{
		ft_draw_image(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		e->render = 1;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *e)
{
	if (button == 1)
	{
		ft_putnbrendl(x);
		ft_putnbrendl(y);
	}
	return (0);
}

int		key_hook(int keycode, t_mlx *e)
{
	if (keycode == MLX_KEY_ESC)
	{
		ft_memdel((void **)e->tab);
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		free(e->mlx);
		exit(0);
	}
	if (keycode == MLX_KEY_RIGHT)
	{
		e->alpha = e->alpha - 5;
		if (e->alpha == -360)
			e->alpha = 0;
		ft_mlx_i_clear_img(e->img, WIN_X, WIN_Y);
		e->render = 0;
		expose_hook(e);
	}
	if (keycode == MLX_KEY_LEFT)
	{
		e->alpha = e->alpha + 5;
		if (e->alpha == 360)
			e->alpha = 0;
		ft_mlx_i_clear_img(e->img, WIN_X, WIN_Y);
		e->render = 0;
		expose_hook(e);
	}
	return (0);
}
