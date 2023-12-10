# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 02:42:35 by ahooghe           #+#    #+#              #
#    Updated: 2023/12/10 23:53:38 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -rf
GNL=libs/get_next_line/gnl.a
GNL_DIR=libs/get_next_line
MLX=libs/minilibx-linux/libmlx.a
MLX_DIR=libs/minilibx-linux
SRCS=srcs/utils/utils3.c srcs/utils/utils.c srcs/utils/utils2.c srcs/movement/handle.c srcs/render/renderer.c srcs/render/mallocpixels.c srcs/render/mlx.c srcs/render/setpixels.c srcs/init/init_mlx.c srcs/init/init_key.c srcs/init/init_file.c srcs/exit/exit.c srcs/parsing/map.c srcs/parsing/textures.c srcs/parsing/file.c srcs/parsing/colors.c srcs/parsing/parse_file.c srcs/parsing/check.c srcs/parsing/create_textures.c srcs/main.c

all:
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(GNL) $(MLX) -o $(NAME) -lm -lX11 -lXext

clean:
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(MAKE) -C $(GNL_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re