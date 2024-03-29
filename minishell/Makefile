# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 18:37:04 by jkasongo          #+#    #+#              #
#    Updated: 2022/07/04 16:34:07 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES_DIR = includes/
READLINE_DIR = ./readline
SRCS_DIR = sources/
OBJS_DIR = objs/

#style
GREEN = \033[0;32m
RED = \033[0;31m
RESET_COLOR = \033[0m

#parser source
PARSER_SRC = parser.c parser_utils.c
PARSER_PREFIXED = $(addprefix parser/, $(PARSER_SRC))

#tokenizer source
TOKENIZER_SRC = tokenizer.c token.c token_special.c token_utils.c
TOKENIZER_PREFIXED = $(addprefix tokenizer/, $(TOKENIZER_SRC))

#lexer normal
LEXER_SRC = lexer.c lexer_utils.c lexer_utils_suite.c heredoc_lex.c
LEXER_PREFIXED = $(addprefix minishell_lexer/, $(LEXER_SRC))

#execution source
EXECUTION_SRC = execute.c execute_utils.c pipelines.c pipelines_utils.c ft_execve.c redirections.c heredoc.c heredoc_suite.c cmd_path.c
EXECUTION_PREFIXED = $(addprefix executions/, $(EXECUTION_SRC))

#lexer bonus

#lexer full shell

#status
STATUS_SRC = bar.c environement.c sub_shell.c signals.c path.c
STATUS_PREFIXED = $(addprefix status/, $(STATUS_SRC))

#builtins source
BUILTINS_SRC = exit.c cd_cmd.c pwd.c echo.c env_cmd.c export.c unset.c export_cmd_utils.c
BUILTINS_PREFIXED = $(addprefix builtins/, $(BUILTINS_SRC))

SRCS = main.c loop.c command_mode.c $(STATUS_PREFIXED) $(TOKENIZER_PREFIXED) $(LEXER_PREFIXED) $(PARSER_PREFIXED) \
						$(EXECUTION_PREFIXED) $(BUILTINS_PREFIXED)
SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#includes
INCLUDES_FILES = minishell.h tokenizer.h status.h parser.h lexer.h pipelines.h
INCLUDES_PREFIXED = $(addprefix $(INCLUDES_DIR), $(INCLUDES_FILES))

#objsm
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRCS))

.PHONY	: all clean fclean re help launch

all : $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@mkdir $(OBJS_DIR)/status
	@mkdir $(OBJS_DIR)/tokenizer
	@mkdir $(OBJS_DIR)/minishell_lexer
	@mkdir $(OBJS_DIR)/parser
	@mkdir $(OBJS_DIR)/executions
	@mkdir $(OBJS_DIR)/builtins

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES_PREFIXED)
	$(CC) $(CFLAGS) -I./$(INCLUDES_DIR) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS_PREFIXED)
	@$(MAKE) re -C ./libft
	@$(CC) $(CFLAGS) $(OBJS_PREFIXED) -L$(READLINE_DIR) -lreadline  -lcurses -L./libft -lft -o $(NAME)
	@echo $(NAME) est construit

clean :
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)cleaning objs$(RESET_COLOR)"

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)
	@echo "$(RED)full clean$(RESET_COLOR)"

re : fclean all
	@echo "$(GREEN) rebuild $(RESET_COLOR)"

launch :all
	./minishell

help :
	@echo ' all clean fclean re launch help minishell'
