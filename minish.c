/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 12:00:33 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** Функция цикличного чтения строки
*/

void		read_input(t_ptr *ptr)
{
	char	*line;

	while (1)
	{
		ft_putstr("(^_^)> ");
		get_next_line(&line);
		line_parsing(line, ptr);
		test_parsing(ptr);
		clear_malloc(ptr);
	}
}

/*
** Обработка сигнала на ctrl + D, ctrl + C и ctrl + \
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
