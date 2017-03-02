# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 14:05:46 by jgengo            #+#    #+#              #
#    Updated: 2017/03/02 14:03:18 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
LIB				= libft/libft.a
LIBMLX			= minilibx_macos/libmlx.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
SRCS			= srcs/main.c \
				  srcs/core.c \
				  srcs/drawin.c \
				  srcs/threadin.c \
				  srcs/events.c \
				  srcs/mandelbrot.c \
				  srcs/julia.c

all: $(NAME)

display:
	@echo "*******************"
	@echo "**project fractol**"
	@echo "*******************\n\n"
$(NAME): display $(LIBMLX) $(LIB) $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)
	@echo "FRACTOL COMPILED\t\033[0;32m✓\033[0m"

$(LIBMLX):
	@make -C minilibx_macos
	@echo "MINILIBX COMPILED\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@make -C minilibx_macos clean
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIBMLX)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
