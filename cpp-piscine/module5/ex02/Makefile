# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 21:29:46 by ryebadok          #+#    #+#              #
#    Updated: 2023/03/14 12:27:19 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- Variables -------------------------------- #
NAME = TryCatch
ROOT = .
INC = .
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
COPTIONS = 

# Personal variables for personnal rules
NM = norminette
CA = clear all
RM = rm -rf
RMD = rmdir

# For object files
OBJ = ofiles

# -------------------------------- Header files ----------------------------- #
HFILES = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

# -------------------------------- CPP FILES ---------------------------------- #
MAIN_CPP = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

# -------------------------------- CPP FILES ---------------------------------- #
TEST_CPP = 

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
	@echo "\033[0;33m $(NAME) is succesfuly built." "\033[0;32m Usage: ./$(NAME)"

$(OBJ):
	@mkdir -p $(OBJ)

check:
	@$(NM)

clear:
	@$(CA)

leaks:
	@leaks --atExit -- ./$(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) *_shrubbery
	@$(RMD) $(OBJ)

re: fclean all

.PHONY: all clean fclean re norme
