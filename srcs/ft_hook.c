/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:27:39 by cledant           #+#    #+#             */
/*   Updated: 2016/02/11 11:09:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_mlx *e)
{
	struct timeval	s_ms[2];
	long int		ms[2];
	double			fps;
	char			*s_fps;
	char			*disp_fps;

	gettimeofday(&(s_ms[0]), NULL);
	ft_draw_image(e);
	gettimeofday(&(s_ms[1]), NULL);
	ms[0]= s_ms[0].tv_sec * 1000 + s_ms[0].tv_usec / 1000;
	ms[1]= s_ms[1].tv_sec * 1000 + s_ms[1].tv_usec / 1000;
	fps = ms[1] - ms[0];
	fps = 1 / (fps / 1000);
	s_fps = ft_itoa((int)fps);
	disp_fps = ft_strjoin("FPS : ", s_fps);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 1100, 50, 0x00FFFFFF, disp_fps);
	ft_strdel(&s_fps);
	ft_strdel(&disp_fps);
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

int		mouse_motion(int x, int y, t_mlx *e)
{
	int 	delta_x;

	if ((x >= 0 && x <= WIN_X) && (y >=0 && y <= WIN_Y))
	{
		delta_x = -x + e->x_mouse_old;
		e->alpha += (delta_x / 2);
		if (e->alpha >= 360)
			e->alpha -= 360;
		else if (e->alpha <= -360)
			e->alpha += 360;
		e->rad_alpha = ft_angle_dec_to_rad(e->alpha);
	}
	e->x_mouse_old = x;
	return (0);
}

int		key_hook(int keycode, t_mlx *e)
{
	double	tmp_sin;
	double	tmp_cos;

	if (keycode == MLX_KEY_ESC)
	{
		ft_memdel((void **)e->tab);
		ft_clear_texture(e);
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		free(e->mlx);
		exit(0);
	}
	if (keycode == MLX_KEY_RIGHT)
	{
		if (ft_check_collision(e, e->alpha - 90, 15) == 1)
		{
			e->x_player = e->x_player + sin(e->rad_alpha) * e->speed;
			e->y_player = e->y_player + cos(e->rad_alpha) * e->speed;
		}
	}
	if (keycode == MLX_KEY_LEFT)
	{
		if (ft_check_collision(e, e->alpha + 90, 15) == 1)
		{
			e->x_player = e->x_player - sin(e->rad_alpha) * e->speed;
			e->y_player = e->y_player - cos(e->rad_alpha) * e->speed;
		}
	}
	if (keycode == MLX_KEY_UP)
	{
		if (ft_check_collision(e, e->alpha, 15) == 1)
		{
			e->x_player = e->x_player + cos(e->rad_alpha) * e->speed;
			e->y_player = e->y_player - sin(e->rad_alpha) * e->speed;
		}
	}
	if (keycode == MLX_KEY_DOWN)
	{
		if (ft_check_collision(e, e->alpha + 180, 10) == 1)
		{
			e->x_player = e->x_player - cos(e->rad_alpha) * e->speed;
			e->y_player = e->y_player + sin(e->rad_alpha) * e->speed;
		}
	}
	return (0);
}
