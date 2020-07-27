# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 07:21:41 by ckakuna           #+#    #+#              #
#    Updated: 2020/07/27 09:37:20 by ckakuna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Werror -Wextra
HDRS = ./minish.h
SRCS = ./srcs/clear_malloc.c ./minish.c ./srcs/error.c ./srcs/line_space.c ./srcs/line_parse.c  ./srcs/line_space_counter.c ./srcs/cd_command.c ./srcs/pwd_command.c ./srcs/external_command.c
SRCS_PARS = ./srcs/parser/parser_echo.c ./srcs/parser/parser_base.c ./srcs/parser/parser_cd.c ./srcs/parser/parser_pwd.c ./srcs/parser/parser_export.c ./srcs/parser/parser_unset.c ./srcs/parser/parser_env.c ./srcs/parser/parser_exit.c ./srcs/parser/parser_external.c
SRCS_UTILS = ./utils/ft_strlcpy.c ./utils/ft_strchr.c ./utils/ft_strcmp.c ./utils/ft_putstr.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/get_next_line.c ./utils/ft_mass_len.c ./utils/ft_realloc_mass.c ./utils/ft_strdup.c ./utils/ft_free_array.c
TESTS = ./test.c
OBJ = $(SRCS:.c=.o) $(SRCS_UTILS:.c=.o) $(SRCS_PARS:.c=.o) $(TESTS:.c=.o)

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