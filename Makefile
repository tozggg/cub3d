# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 17:20:13 by jeson             #+#    #+#              #
#    Updated: 2022/04/11 17:49:11 by jeson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_B = cub3d_bonus

INC_DIR = ./include/
SRC_DIR = ./src/
SRC_B_DIR = ./src_bonus/
LIB_DIR = ./libft/
MLX_DIR = ./mlx/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

SRC		=	check_map.c check.c init.c key.c move.c \
			parse.c play.c raycasting.c set_dir_plane.c \
			utils.c main.c

SRC_B	=	check_map_bonus.c check_bonus.c init_bonus.c \
			key_bonus.c move_bonus.c parse_bonus.c play_bonus.c \
			raycasting_bonus.c set_dir_plane_bonus.c utils_bonus.c \
			main_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

SRCS_B = $(addprefix $(SRC_B_DIR), $(SRC_B))
OBJS_B = $(SRCS_B:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -I $(INC_DIR) $(LIBFLAGS)

all : $(NAME)

$(NAME_B) : $(OBJS_B)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME_B) $(OBJS_B) -I $(INC_DIR) $(LIBFLAGS)

bonus : $(NAME_B)

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME) $(NAME_B)

re : clean all

.PHONY : all clean fclean re bonus
