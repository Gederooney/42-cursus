# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 08:39:14 by ryebadok          #+#    #+#              #
#    Updated: 2021/06/07 17:39:47 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft/
LIBFTA		= libft.a
MAKELIBFT	= make bonus -C $(LIBFT)
CLEANLIBFT	= make clean -C $(LIBFT)
FCLEANLIBFT	= make fclean -C $(LIBFT)
SRCS		= srcs/ft_convertc.c \
			  srcs/ft_converts.c \
			  srcs/ft_convertp.c \
			  srcs/ft_convertd.c \
			  srcs/ft_convertx.c \
			  srcs/ft_convert_X.c \
			  srcs/ft_getinfos.c \
			  srcs/ft_printf.c \
			  srcs/utils.c \

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf
LIBC		= ar -rcs
FLAGS		= -Wall -Werror -Wextra -c 
INCS		= .
CC			= gcc
CP			= cp

.c.o:
	@$(CC) $(FLAGS) $< -o $(<:.c=.o) -I$(INCS)

$(NAME):$(OBJS)
		@$(MAKELIBFT)
		@$(CP) $(LIBFT)$(LIBFTA) $(NAME)
		@$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(CLEANLIBFT)

fclean: clean
		@$(RM) $(NAME)
		@$(FCLEANLIBFT)

re: fclean all

.PHONY: all clean fclean re .c.o