# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 14:05:46 by jgengo            #+#    #+#              #
#    Updated: 2017/03/01 17:04:00 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
LIB				= libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -lmlx -framework OpenGL -framework AppKit
SRCS			= srcs/main.c \
				  srcs/core.c \
				  srcs/drawin.c \
				  srcs/events.c \
				  srcs/julia.c

all: $(NAME)

display:
	@echo "*******************"
	@echo "**project fractol**"
	@echo "*******************\n\n"
$(NAME): display $(LIB) $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)
	@echo "FRACTOL COMPILED\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
