# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 07:50:04 by ryebadok          #+#    #+#              #
#    Updated: 2022/12/17 11:58:13 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- Variables -------------------------------- #
NAME = harl
ROOT = .
INC = .
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = g++
COPTIONS = 

# Personal variables for personnal rules
NM = norminette
CA = clear all
RM = rm -rf
RMD = rmdir

# For object files
OBJ = ofiles

# -------------------------------- Header files ----------------------------- #
HFILES = Harl.hpp

# -------------------------------- CPP FILES ---------------------------------- #
MAIN_CPP = main.cpp Harl.cpp

# -------------------------------- CPP FILES ---------------------------------- #
TEST_CPP = test.cpp

# -------------------------------- DIRECTORIES PATHS ------------------------ #
MAIN_DIR = .

# -------------------------------- SOURCES FILES ---------------------------- #
MAIN_SRCS = $(addprefix $(MAIN_DIR)/, $(MAIN_CPP))

# -------------------------------- OBJECTS FILES ---------------------------- #
OFILES = $(MAIN_CPP:.cpp=.o) $(TEST_CPP:.cpp=.o)

HEADERS = $(addprefix $(INC)/, $(HFILES))

OBJS = $(addprefix $(OBJ)/, $(OFILES))
SRCS = $(MAIN_SRCS)

VPATH = $(MAIN_DIR)
# -------------------------------- RULES ------------------------------------ #
$(OBJ)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -I. -I$(INC) $< -o $@ 

$(NAME): $(OBJ) $(OBJS)
	$(CC) $(COPTIONS) $(OBJS) -o $(NAME)
	@clear
	@echo "\033[0;33m $(NAME) is succesfuly built." "\033[0;32m Usage: ./$(NAME) [filnename] [string1] [string2]"

$(OBJ):
	@mkdir -p $(OBJ)

check:
	@$(NM)

clear:
	@$(CA)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RMD) $(OBJ)

re: fclean all

.PHONY: all clean fclean re norme
