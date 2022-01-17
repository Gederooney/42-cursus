# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 08:22:39 by ryebadok          #+#    #+#              #
#    Updated: 2021/10/06 17:52:23 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = -lmlx
MLXLIB = /usr/local/lib/
MLXHEADER = ./minilibx

CC = cc
FRAMEWORK = -framework OpenGL -framework Appkit

FLAGS = -Wall -Werror -Wextra

SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c \
		utils/ft_lstadd_back.c utils/ft_lstlast.c utils/ft_lstnew.c \
		utils/ft_lstsize.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c \
		utils/ft_putnbr_fd.c utils/ft_itoa.c utils/ft_freestruct.c \
		actions/ft_handle_left.c actions/ft_handle_right.c actions/ft_handle_up.c  actions/ft_handle_down.c\
		sources/ft_read_map.c sources/ft_parse.c sources/ft_create_world.c\
		sources/ft_run.c sources/ft_freegame.c sources/ft_init_world.c\
		animations/ft_moves.c animations/ft_render.c\
		main.c \

OBJS = $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)
	@echo "\033[0;33m so_long built." "\033[0;32m Usage ==> ./so_long path_to_map"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -I $(MLXHEADER) -L $(MLXLIB) $(MLX) $(FRAMEWORK) -o $(NAME)
	
clean:
	@clear all
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re