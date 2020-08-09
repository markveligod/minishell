/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/06 09:32:39 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** Функция для получения path к текущей директории
*/

char		*get_pwd(char **env)
{
	int		i;
	int		j;
	char	*temp;
	char	*path;

	i = 0;
	temp = ft_strdup("");
	while (env[i])
	{
		if (ft_strcmp(env[i], "LOGNAME") == 0)
		{
			free(temp);
			temp = ft_strdup(env[++i]);
			break ;
		}
		i++;
	}
	temp = ft_strjoin(temp, ":");
	path = getcwd(NULL, 10);
	j = ft_strlen(path);
	while (path[--j])
		if (path[j] == '/')
		{
			temp = ft_strjoin(temp, &path[++j]);
			break ;
		}
	free(path);
	return (ft_strjoin(temp, " $> "));
}

/*
** Функция цикличного чтения строки
*/

void		read_input(t_ptr *ptr)
{
	char	*line;

	while (1)
	{
		if (g_pwd)
			free(g_pwd);
		g_pwd = get_pwd(ptr->is_env);
		ft_putstr(g_pwd);
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
	{
		if (g_flag == 1)
			ft_putstr("\n");
		else
		{
			ft_putstr("\n");
			ft_putstr(g_pwd);
			//ft_putstr(" $> ");
		}
	}
	else if (signum == SIGQUIT)
	{
		if (g_flag == 1)
			ft_putstr("Quit: 3\n");
		/*else
		{
			//ft_putstr("\n");
			//ft_putstr(g_pwd);
			//ft_putstr(" $> ");
		}*/
	}
}

int			main(int ac, char **av, char **env)
{
	t_ptr 	ptr;

	g_flag = 0;
	g_curr_err = "0";
	g_pwd = NULL;
	init_struct_ptr(&ptr);
	ptr.is_env = parser_env(env);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	read_input(&ptr);
	return (0);
}
