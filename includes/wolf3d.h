/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:35:05 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 09:44:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> //caca
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"
# define PLAYER_X_START 250
# define PLAYER_Y_START 250
# define MLX_KEY_ESC 53
# define MLX_KEY_RIGHT 124
# define MLX_KEY_LEFT 123
# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define WIN_X 1280
# define WIN_Y 720
# define C_SIZE 64
# define FOV 60
# define ROT_SPEED 2
# define SPEED 10
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L<<6)

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
	int		x_mouse_old;
	void	*img_bluestone;
	void	*img_redbrick;
	void	*img_wood;
	void	*img_d_fawn;
	void	*img_rooftiles4;
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
void			ft_mlx_i_to_i_cpy_pixel(void *dst_i, void *src_i, int d_coord[2],
					int s_coord[2]);
int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
int				mouse_hook(int button, int x, int y);
int				mouse_motion(int x, int y, t_mlx *e);
size_t			ft_lstseek_max_x(t_list *list);
void			ft_putendl_int2(int **tab, int x, int y); //delete a la fin
int				**ft_fill_int_tab2(t_list *list, int x, int y);
int				ft_lstsplit_whitespaces_content(t_list *list);
int				ft_what_faces_ray(double alpha);
int				ft_what_faces_ray_for_verti(double alpha);
int				ft_check_wall(t_mlx *e, int r_x, int r_y);
double			ft_horizontal_intersection(t_mlx *e, double alpha[4], int *wall_type,
					double (*int_coord)[2]);
double			ft_vertical_intersection(t_mlx *e, double alpha[4], int *wall_type,
					double (*int_coord)[2]);
double			ft_ray_lenght(int *begin, double *end, double rad_alpha, double alpha);
double			ft_select_ray(t_mlx *e, double angle[4], int *wall_type,
					double (*int_coord)[2]);
void			ft_draw_image(t_mlx *e);
int				ft_check_collision(t_mlx *e, double angle, size_t d_collision);
int				ft_load_texture(t_mlx *e);
void			ft_clear_texture(t_mlx *e);
void			ft_draw_texture(t_mlx *e, int disp_i_col, int begin, int end,
					int type, double coord[2], int overflow);
void			ft_draw_texture(t_mlx *e, int disp_i_col, int begin, int end,
					int type, double coord[2], int overflow);
void			ft_draw_floor(t_mlx *e, int disp_i_col, int begin, int end,
					int type, double angle[4]);
void			ft_draw_ceiling(t_mlx *e, int disp_i_col, int begin, int end,
					int type, double angle[4]);

#endif
