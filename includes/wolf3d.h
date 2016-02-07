/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:35:05 by cledant           #+#    #+#             */
/*   Updated: 2016/02/07 21:45:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> //caca
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# define MLX_KEY_ESC 53
# define MLX_KEY_RIGHT 124
# define MLX_KEY_LEFT 123
# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define WIN_X 1280
# define WIN_Y 720
# define C_SIZE 64
# define FOV 60
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		render;
	void	*img;
	int		**tab;
	int		y_max;
	int		x_max;
	int		alpha;
	double	rad_alpha;
	int		speed;
	int		x_player;
	int		y_player;
	size_t	dist_to_proj_plane;
	double	inc_alpha;
}				t_mlx;

char			*ft_mlx_i_position_in_2d(void *img, int i, int j);
void			ft_mlx_i_pixel_put(void *img, int x, int y, int color);
int				ft_mlx_i_drawline(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_hori_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_verti_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag1_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag2_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag3_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag4_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag5_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag6_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag7_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_draw_diag8_line(void *e, int *p1, int *p2, int color);
void			ft_mlx_i_clear_img(void *img, int i, int j);
int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
int				mouse_hook(int button, int x, int y, t_mlx *e);
size_t			ft_lstseek_max_x(t_list *list);
void			ft_putendl_int2(int **tab, int x, int y); //delete a la fin
int				**ft_fill_int_tab2(t_list *list, int x, int y);
int				ft_lstsplit_whitespaces_content(t_list *list);
int				ft_seek_pos_x_player(int **tab, int x, int y);
int				ft_seek_pos_y_player(int **tab, int x, int y);
int				ft_what_faces_ray(double alpha);
int				ft_what_faces_ray_for_verti(double alpha);
double			ft_angle_dec_to_rad(double dec);
int				ft_check_wall(t_mlx *e, int r_x, int r_y);
double			ft_horizontal_intersection(t_mlx *e, double alpha,
					int player_x, int player_y);
double			ft_vertical_intersection(t_mlx *e, double alpha,
					int player_x, int player_y);
double			ft_ray_lenght(int *begin, double *end, double rad_alpha, int alpha);
double			ft_select_ray(t_mlx *e, double angle[2], int player_x,
					int player_y);
size_t			ft_wall_height(t_mlx *e, double angle[2]);
void			ft_draw_image(t_mlx *e);
int				ft_check_collision(t_mlx *e, double angle);

#endif
