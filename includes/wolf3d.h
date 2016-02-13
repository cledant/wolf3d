/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:35:05 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 20:48:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"
# define PLAYER_X_START 640
# define PLAYER_Y_START 640
# define MLX_KEY_ESC 53
# define MLX_KEY_RIGHT 124
# define MLX_KEY_LEFT 123
# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define WIN_X 1280
# define WIN_Y 720
# define C_SIZE 64
# define FOV 60
# define SPEED 10
# define ANIM_SPEED 3
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L<<6)

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		render;
	int		**tab;
	int		y_max;
	int		x_max;
	int		alpha;
	double	rad_alpha;
	double	cos_rad_alpha;
	double	sin_rad_alpha;
	int		speed;
	double	x_player;
	double	y_player;
	size_t	dist_to_proj_plane;
	double	inc_alpha;
	int		x_mouse_old;
	int		counter_chu;
	void	*img;
	void	*img_redbrick;
	void	*img_wood;
	void	*img_brown20;
	void	*img_cobblestone;
	void	*img_diamondred;
	void	*img_patternbrown;
	void	*img_woodherring2;
	void	*img_woodrough;
	void	*img_redgreycheck2;
	void	*img_greygreencheck;
	void	*img_hexbrown;
	void	*img_c1;
	void	*img_c2;
	void	*img_c3;
	void	*img_c4;
	void	*img_c5;
	char	*char_img;
	char	*redbrick;
	char	*wood;
	char	*brown20;
	char	*cobblestone;
	char	*diamondred;
	char	*patternbrown;
	char	*woodherring2;
	char	*woodrough;
	char	*redgreycheck2;
	char	*greygreencheck;
	char	*hexbrown;
	char	*c1;
	char	*c2;
	char	*c3;
	char	*c4;
	char	*c5;
}				t_mlx;

void			ft_mlx_c_to_c_cpy_pixel(char *dest_i, char *src_i,
					int d_coord[2], int s_coord[2], int d_sizeline,
					int s_sizeline);
int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
int				mouse_motion(int x, int y, t_mlx *e);
size_t			ft_lstseek_max_x(t_list *list);
int				**ft_fill_int_tab2(t_list *list, int x, int y);
int				ft_lstsplit_whitespaces_content(t_list *list);
int				ft_what_faces_ray(double alpha);
int				ft_what_faces_ray_for_verti(double alpha);
int				ft_check_wall(t_mlx *e, int r_x, int r_y);
double			ft_horizontal_intersection(t_mlx *e, double alpha[8],
					int *wall_type, double (*int_coord)[2]);
double			ft_vertical_intersection(t_mlx *e, double alpha[8],
					int *wall_type, double (*int_coord)[2]);
double			ft_ray_lenght(int *begin, double *end, double angle[8]);
double			ft_select_ray(t_mlx *e, double angle[8], int *wall_type,
					double (*int_coord)[2]);
void			ft_draw_image(t_mlx *e);
int				ft_check_collision(t_mlx *e, double angle, size_t d_collision);
int				ft_load_texture(t_mlx *e);
void			ft_clear_texture(t_mlx *e);
void			ft_clear_texture_2(t_mlx *e);
void			ft_draw_texture(t_mlx *e, int disp_i_col, int begin, int end,
					int type, double coord[2], int overflow);
void			ft_draw_texture(t_mlx *e, int disp_i_col, int begin, int end,
					int type, double coord[2], int overflow);
void			ft_draw_ceiling_floor(t_mlx *e, int disp_i_col, int begin[2],
					int end[2], double angle[8]);
void			ft_alloc_img_char(t_mlx *e);
void			ft_alloc_img_char_2(t_mlx *e);
void			ft_change_anim(t_mlx *e);
void			ft_init_struct(t_mlx *e);
void			ft_free_all(t_mlx *e);

#endif
