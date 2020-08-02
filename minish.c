/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/02 08:48:38 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** 
*/

char		*get_pwd(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], "PWD") == 0)
			return (ft_strdup(env[++i]));
		i++;
	}
	return (NULL);
}

/*
** Функция цикличного чтения строки
*/

void		read_input(t_ptr *ptr)
{
	char	*line;
	char	*pwd;

	while (1)
	{
		pwd = get_pwd(ptr->is_env);
		ft_putstr(pwd);
		ft_putstr(" $> ");
		free(pwd);
		get_next_line(&line);
		line_parsing(line, ptr);
		test_parsing(ptr);
		clear_malloc(ptr);
	}
}

/*
** Обработка сигнала на ctrl + C (SIGINT) и ctrl + \ (SIGQUIT)
*/

void		sighandler(int signum)
{
	if (signum == SIGINT)
		ft_putstr("\n");
	else if (signum == SIGQUIT)
		ft_putstr("Quit: 3\n");
}

int			main(int ac, char **av, char **env)
{
	t_ptr 	ptr;

	init_struct_ptr(&ptr);
	ptr.is_env = parser_env(env);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	read_input(&ptr);
	return (0);
}
