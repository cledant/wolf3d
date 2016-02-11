/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/02/11 09:42:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		main_part1(t_mlx *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Wolf_3D");
	if (e->win == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	if (e->img == NULL)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

static int		main_part1_5(t_mlx *e, t_list *lst)
{
	int		**tab;

	tab = ft_fill_int_tab2(lst, e->x_max, e->y_max);
	if (tab == NULL)
	{
		ft_lstdel(&lst, &ft_bzero);
		ft_putendl("Error");
		return (0);
	}
	ft_lstdel(&lst, &ft_bzero);
	e->tab = tab;
	e->render = 0;
	e->alpha = 0;
	e->rad_alpha = 0;
	e->dist_to_proj_plane = (WIN_X / 2) / tan(ft_angle_dec_to_rad(90 - FOV));
	e->inc_alpha = FOV / ((double)WIN_X);
	e->x_player = PLAYER_X_START;
	e->y_player = PLAYER_Y_START;
	e->speed = SPEED;
	e->x_mouse_old = WIN_X / 2;
	return (1);
}

static int		main_part2(t_mlx *e, int fd, t_list *lst)
{
	if ((lst = ft_lstread_file(fd)) == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	if (ft_lstsplit_whitespaces_content(lst) == 0)
	{
		ft_lstdel(&lst, &ft_bzero);
		ft_putendl("Error");
		return (0);
	}
	e->y_max = ft_lstcount_node(lst);
	e->x_max = ft_lstseek_max_x(lst);
	if (e->x_max == 0 || (e->y_max == 1 && e->x_max == 1))
	{
		ft_putendl("Error");
		ft_lstdel(&lst, &ft_bzero);
		return (0);
	}
	if (main_part1_5(e, lst) == 0)
		return (0);
	return (1);
}

static void		ft_free_all(t_mlx *e)
{
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	ft_memdel((void **)e->tab);
}

int				main(void)
{
	t_mlx		e;
	t_list		*lst;
	int			fd;

	lst = NULL;
	if ((fd = open("maps/wolf.map", O_RDONLY)) < 0)
	{
		ft_putendl("Error loading map");
		return (0);
	}
	if (main_part1(&e) == 0)
		return (0);
	if (ft_load_texture(&e) == 0)
	{
		ft_clear_texture(&e);
		ft_putendl("Error loading texture");
		return (0);
	}
	if ((main_part2(&e, fd, lst)) == 0)
		return (0);
	if (close(fd) == -1)
	{
		ft_free_all(&e);
		return (0);
	}
	ft_putendl_int2(e.tab, e.x_max, e.y_max); //delete apres check
	mlx_hook(e.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, &e);
	mlx_hook(e.win, MOTION_NOTIFY, POINTER_MOTION_MASK, mouse_motion, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
