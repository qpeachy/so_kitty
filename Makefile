# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:48:35 by mapale            #+#    #+#              #
#    Updated: 2024/03/20 14:07:44 by mapale           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g3 #-fsanitize=address
HEADER_FILE		=	so_long.h
SRC_PATH		=	srcs/
DIR_BUILD		=	.build/
SRCS			=	so_long.c				\
					get_next_line.c			\
					get_next_line_utils.c 	\
					mlx_tools.c				\
					utils.c					\
					parsing.c				\
					parsing_utils.c			\
					doable.c				\
					key_hook.c				\
					set_textures.c			\
					removeAFTER.c			\

OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))


MLX_PATH		= mlx/
MLX_INCLUDES	= $(MLX_PATH)
MLX_L			= -L $(MLX_PATH) -l mlx
MLX_A			= $(MLX_PATH)libmlx.a
MLX_MAKE		= $(MAKE) -C $(MLX_PATH)

DIR_INCS =\
	includes/			\
	$(MLX_INCLUDES)

INCLUDES =\
	$(addprefix -I , $(DIR_INCS))

LIBS = \
	-lm	\
	$(MLX_L)	\
	-lXext	\
	-lX11

DEPENDENCIES =\
	$(MLX_A)

all:
			$(MLX_MAKE)
			$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

$(DIR_BUILD)%.o:$(SRC_PATH)%.c
	@mkdir -p $(DIR_BUILD)
	$(CC) $(CFLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	$(MLX_MAKE)

VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all\
			--track-fds=yes --show-mismatched-frees=yes --track-origins=yes -s

leaks		:	all
			$(VALGRIND) ./$(NAME) $(ARGS)

clean:
	$(MLX_MAKE) clean
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all

.PHONY: all clean fclean re
