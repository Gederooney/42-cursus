# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 13:41:12 by ryebadok          #+#    #+#              #
#    Updated: 2021/08/07 14:47:48 by ryebadok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
FLAGS = -Wall -Werror -Wextra

SERVER_SRCS = server.c utils.c utils_2.c
CLIENT_SRCS = client.c utils.c utils_2.c

BONUS_SERVER_SRCS = server_bonus.c utils.c utils_2.c
BONUS_CLIENT_SRCS = client_bonus.c utils.c utils_2.c

CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)

BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRCS:%.c=%.o)
BONUS_SERVER_OBJS = $(BONUS_SERVER_SRCS:%.c=%.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER)
	@echo "Server built"

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT)
	@echo "Client built"

bonus: fclean $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)
	@$(CC) $(FLAGS) $(BONUS_CLIENT_OBJS) -o $(CLIENT)
	@$(CC) $(FLAGS) $(BONUS_SERVER_OBJS) -o $(SERVER)
clean:
	@rm -f $(SERVER_OBJS)
	@rm -f $(BONUS_SERVER_OBJS)
	@rm -f $(CLIENT_OBJS)
	@rm -f $(BONUS_CLIENT_OBJS)
fclean: clean
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@clear all
re: fclean all
.PHONY: all clean fclean re