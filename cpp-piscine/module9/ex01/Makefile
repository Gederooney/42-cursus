# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 01:14:24 by mleblanc          #+#    #+#              #
#    Updated: 2023/05/12 21:45:20 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RPN
MAX_WIDTH	=	77
DONE_MESSAGE=	"Compilation terminée"
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wconversion -Wshadow -std=c++98
CC			=	c++
RM			=	rm -rf
COLOR := $$(printf "\033[1;32m")

OBJ			=	obj

NAME_LENGTH := $(shell echo '$(NAME)' | wc -c)


EQUALS_LINE := $$(printf "=%.0s" $$(seq 1 $$(($(MAX_WIDTH)))))
EQUALS_DOTS:= $$(printf ".%.0s" $$(seq 1 $$(($(MAX_WIDTH)))))

INCS		=	RPN.hpp
SRCS		=	main.cpp RPN.cpp
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.cpp=.o))

run: all
	./${NAME} "8 9 *  9 - 9 - 9 - 4 - 1  +"
	./${NAME} "3 -4 + "
	./${NAME} "77 * 7 - "
	./${NAME} "5 0 / "
$(OBJ)/%.o:	%.cpp
			@echo "Compiling $<..."
			$(CC) $(CFLAGS) -I. -c $< -o $@

build: $(NAME)

all:		CFLAGS += -O2
all:		build


debug:		CFLAGS += -g -fno-limit-debug-info
debug:		$(NAME)

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -o $(NAME)
	@echo ""; 
	@echo "$(COLOR)$(EQUALS_LINE)\033[0m";
	@echo "$(COLOR)$(EQUALS_DOTS)\033[0m";
	@echo
	@echo 
	@echo "$(COLOR)$(SPACE)$(DONE_MESSAGE)$(SPACE)\033[0m";
	@echo "$(COLOR)$(SPACE)$(NAME)$(SPACE)\033[0m";
	@echo
	@echo
	@echo "$(COLOR)$(EQUALS_DOTS)\033[0m";
	@echo "$(COLOR)$(EQUALS_LINE)\033[0m";

$(OBJ):
			@mkdir -p $(OBJ)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME) $(OBJ)

re:			fclean all

format:
			# @clang-format -i $(SRCS) $(INCS)

.PHONY:		 all clean fclean re format debug
