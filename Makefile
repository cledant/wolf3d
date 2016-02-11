# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/02/11 15:59:24 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

//CFLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

INCLUDES_MLX = ./minilibx_macos/includes

LIBFT_PATH = ./libft

LIBMLX_PATH = ./minilibx_macos

SRC_NAME = main.c ft_hook.c ft_mlx_i_pixel_put.c ft_mlx_i_position_in_2d.c \
		   ft_lstseek_max_x.c ft_putendl_int2.c \
		   ft_fill_int_tab2.c ft_lstsplit_whitespaces_content.c \
		   ft_what_faces_ray.c ft_angle_dec_to_rad.c ft_clear_texture.c \
		   ft_check_wall.c ft_horizontal_intersection.c ft_vertical_intersection.c \
		   ft_ray_lenght.c ft_draw_image.c ft_select_ray.c \
		   ft_wall_height.c ft_check_collision.c ft_load_texture.c \
		   ft_mlx_i_draw_verti_line.c ft_mlx_i_drawline.c \
		   ft_mlx_i_draw_hori_line.c ft_mlx_i_draw_diag_line1234.c \
		   ft_mlx_i_draw_diag_line5678.c ft_what_faces_ray_for_verti.c \
		   ft_draw_texture.c ft_mlx_i_to_i_cpy_pixel.c ft_draw_floor.c

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = wolf3d

all :	libft libmlx $(NAME)

libft :
	make -C $(LIBFT_PATH)

libmlx :
	make -C $(LIBMLX_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -lmlx -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_MLX) -L$(LIBFT_PATH) -L$(LIBMLX_PATH) -framework OpenGL -framework Appkit

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(INCLUDES_MLX)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBMLX_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean
	rm -rf $(LIBMLX_PATH)/libmlx.a

re : fclean all

.PHONY : all clean fclean re libft libmlx
