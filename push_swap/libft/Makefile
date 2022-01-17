 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 11:36:15 by ryebadok          #+#    #+#              #
#    Updated: 2021/09/17 08:55:10 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=libft.a

SRCS	=	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlen.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_islower.c \
			ft_isupper.c\
			ft_strcmp.c \
			ft_charcmp.c \
			ft_putnbr_base.c \
			ft_putarray.c \
			ft_putintarray.c \
			ft_arraylen.c \
			ft_freearray.c \
			ft_myfree.c \
			ft_atol.c \

SRCS_BONUS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

CC		=	gcc
FLAGS	=	-c -Wall -Wextra -Werror
LIB		=	ar rcs
RLIB	=	ranlib
RM = rm -f
OBJS	=	$(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: bonus

$(NAME):
	@$(CC) $(FLAGS) $(SRCS)
	@$(LIB) $(NAME) $(OBJS)
	@$(RLIB) $(NAME)

bonus:	$(NAME)
	@$(CC) $(FLAGS) $(SRCS_BONUS)
	@$(LIB) $(NAME) $(OBJS_BONUS)
	@$(RLIB) $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
