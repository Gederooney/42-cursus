# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 08:15:39 by ryebadok          #+#    #+#              #
#    Updated: 2021/11/19 11:44:35 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- Variables -------------------------------- #
NAME = philo
ROOT = srcs
INC = includes
CFLAGS = -Wall -Werror -Wextra
CC = gcc
COPTIONS = -lpthread

# Personal variables for personnal rules
NM = norminette
CA = clear all
RM = rm -rf
RMD = rmdir

# For object files
OBJ = ofiles

# -------------------------------- Header files ----------------------------- #
HFILES = philo.h srcs.h types.h utils.h 

# -------------------------------- C FILES ---------------------------------- #
MAIN_C = errors.c main.c parse.c threads.c routine.c
UTILS_C = atoi.c string.c rotate.c array.c time.c

# -------------------------------- DIRECTORIES PATHS ------------------------ #
MAIN_DIR = $(ROOT)/main
UTILS_DIR = $(ROOT)/utils

# -------------------------------- SOURCES FILES ---------------------------- #
MAIN_SRCS = $(addprefix $(MAIN_DIR)/, $(MAIN_C))
UTILS_SRCS = $(addprefix $(UTILS_DIR), $(UTILS_C))

# -------------------------------- OBJECTS FILES ---------------------------- #
OFILES = $(MAIN_C:.c=.o) $(UTILS_C:.c=.o)

HEADERS = $(addprefix $(INC)/, $(HFILES))

OBJS = $(addprefix $(OBJ)/, $(OFILES))
SRCS = $(MAIN_SRCS) $(UTILS_SRCS)

VPATH = $(MAIN_DIR) $(UTILS_DIR)

# -------------------------------- RULES ------------------------------------ #
$(OBJ)/%.o: %.c
	$(CC) $(CFLAGS) -c -I. -I$(INC) $< -o $@ 

$(NAME): $(OBJ) $(OBJS)
	$(CC) $(COPTIONS) $(OBJS) -o $(NAME)
	@clear
	@echo "\033[0;33m philo is succesfuly built." "\033[0;32m Usage ==> ./philo arguments"

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
