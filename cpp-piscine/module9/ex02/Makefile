# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 01:14:24 by mleblanc          #+#    #+#              #
#    Updated: 2023/05/13 15:11:20 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe
MAX_WIDTH	=	77
DONE_MESSAGE=	"Compilation terminée"
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic -Wconversion -Wshadow -std=c++98
CC			=	c++
RM			=	rm -rf
COLOR := $$(printf "\033[1;32m")

OBJ			=	obj

NAME_LENGTH := $(shell echo '$(NAME)' | wc -c)
JOT_OUPUT := $(shell jot -r 10 100 1 | tr '\n' ' ')


EQUALS_LINE := $$(printf "=%.0s" $$(seq 1 $$(($(MAX_WIDTH)))))
EQUALS_DOTS:= $$(printf ".%.0s" $$(seq 1 $$(($(MAX_WIDTH)))))

INCS		=	PmergeMe.hpp
SRCS		=	main.cpp utils.cpp
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.cpp=.o))


$(OBJ)/%.o:	%.cpp
			@echo "Compiling $<..."
			$(CC) $(CFLAGS) -I. -c $< -o $@

build: $(NAME)

all:		CFLAGS += -O2
all:		build
run:
			@./$(NAME) $(JOT_OUPUT)

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
