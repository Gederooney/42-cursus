# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 15:49:38 by ryebadok          #+#    #+#              #
#    Updated: 2021/10/06 18:27:52 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft/
LIBFTA		= libft.a
AOUT		= a.out

MAKELIBFT	= make bonus -C $(LIBFT)
CLEANLIBFT	= make clean -C $(LIBFT)
FCLEANLIBFT	= make fclean -C $(LIBFT)

SRCS		= srcs/main.c srcs/ft_parse.c srcs/ft_initstacks.c \
			  srcs/ft_resolve.c srcs/ft_sort_five.c srcs/ft_radix_sort.c \
			  srcs/ft_newsort.c \
			  utils/ft_free_intarray.c utils/ft_array_issorted.c utils/ft_limits.c\
			  actions/ft_swap.c actions/ft_rotate.c srcs/ft_sort_three.c \
			  actions/ft_rotate_reverse.c actions/ft_push.c\

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf
EXEC		= gcc -o
LIB			= -Llibft -lft
FLAGS		= -Wall -Werror -Wextra -c -g
INCS		= ./includes
CC			= gcc
CP			= cp

.c.o:
	$(CC) $(FLAGS) $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKELIBFT)
	@$(EXEC) $(NAME) $(OBJS) $(LIB)

clean:
	@clear all
	@$(RM) $(OBJS)
	@$(CLEANLIBFT)

fclean: clean
	@$(RM) $(NAME)
	@$(FCLEANLIBFT)
	@$(RM) $(AOUT)

re: fclean all clean

.PHONY: all clean fclean re .c.o
