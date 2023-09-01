# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 11:15:34 by julolle-          #+#    #+#              #
#    Updated: 2023/07/24 11:15:34 by julolle-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

HEADER      := includes/fdf.h

SRC_DIR		:= srcs
SRCS 		:= fdf.c check_file.c save_file.c window.c draw_map.c \
				create_mat_pos.c utils_mat_pos.c keys_functions.c \
				../includes/get_next_line/get_next_line.c \
				../includes/get_next_line/get_next_line_utils.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
		
MLX_DIR 	:= includes/mlx/
MLX_LIB 	:= $(MLX_DIR)libmlx.a
MLX_FLAGS 	:= -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR 	:= includes/libft/
LIBFT		:= $(LIBFT_DIR)/libft.a

OBJS		:= $(SRCS:.c=.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -MMD

RM			:= rm -f

#Implicit Method
%.o: %.c	Makefile $(LIBFT)
	$(CC) $(CFLAGS) -I $(HEADER) -MMD -Imlx -c $< -o $@

# My methods
all:	subsystems $(NAME)

subsystems:
	@make -s -C $(MLX_DIR) 
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(MLX_LIB) -L $(LIBFT_DIR) -lft

clean:
	@$(RM) $(OBJS) $(DEPS)
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all

-include $(DEPS)

# Phony
.PHONY: all clean fclean re