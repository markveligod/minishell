# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckakuna <42.fr>                            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 07:21:41 by ckakuna           #+#    #+#              #
#    Updated: 2020/07/29 07:31:11 by ckakuna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Werror -Wextra
HDRS = ./minish.h
SRCS = ./srcs/parser_env.c ./srcs/clear_malloc.c ./minish.c ./srcs/error.c ./srcs/line_space.c ./srcs/line_parse.c  ./srcs/line_space_counter.c ./srcs/init_structs.c ./srcs/parser_commands.c ./srcs/write_in_file.c
SRCS_COMM = ./srcs/commands/env_command.c ./srcs/commands/cd_command.c ./srcs/commands/pwd_command.c ./srcs/commands/external_command.c ./srcs/commands/do_command.c ./srcs/commands/echo_command.c
SRCS_UTILS = ./utils/ft_strlcpy.c ./utils/ft_strchr.c ./utils/ft_strcmp.c ./utils/ft_putstr.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/get_next_line.c ./utils/ft_mass_len.c ./utils/ft_realloc_mass.c ./utils/ft_strdup.c ./utils/ft_free_array.c ./utils/ftstrjoin.c ./utils/ft_putstr_fd.c
TESTS = ./test.c
OBJ = $(SRCS:.c=.o) $(SRCS_UTILS:.c=.o) $(TESTS:.c=.o) $(SRCS_COMM:.c=.o)

%.o:%.c
	@$(CC) -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[33m Compiling $<\033[0m"

$(NAME): $(OBJ) $(HDRS)
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled minishell project.\033[0m"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m minishell deleted.\033[0m"

re: fclean all

start: all
	@echo "\033[90m[\033[32mStart\033[90m]\033[32m Start minishell... \033[0m"
	@./minishell

.PHONY: all clean fclean re