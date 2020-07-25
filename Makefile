# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckakuna <42.fr>                            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 07:21:41 by ckakuna           #+#    #+#              #
#    Updated: 2020/07/24 17:30:36 by ckakuna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Werror -Wextra
HDRS = ./minish.h
SRCS = ./minish.c ./srcs/error.c ./srcs/create_file_v.c ./srcs/parser_echo.c ./srcs/create_flag_v.c ./srcs/line_space.c ./srcs/line_parse.c
SRCS_UTILS = ./utils/ft_strlcpy.c ./utils/ft_strchr.c ./utils/ft_strcmp.c ./utils/ft_putstr.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/get_next_line.c ./utils/ft_mass_len.c ./utils/ft_realloc_mass.c ./utils/ft_strdup.c ./utils/ft_free_array.c
OBJ = $(SRCS:.c=.o) $(SRCS_UTILS:.c=.o)

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

.PHONY: all clean fclean re