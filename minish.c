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
** Расшифровывает переменную среды (из имени в ее значение);
** Соединяет расшифрованную переменную среды со словом до него,
** если между ними не было пробела;
*/
void		env_value(char **mass, char **env, char **space)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	while (mass[i])
	{
		if (mass[i][0] == '$' && ft_strlen(mass[i]) != 1)
		{
			j = 0;
			name = ft_strdup(mass[i] + 1);
			while (env[j] && ft_strcmp(env[j], name) != 0)
				j++;
			free(mass[i]);
			free(name);
			if (!(env[j]))
				mass[i] = ft_strdup("");
			else
				mass[i] = ft_strdup(env[++j]);

			/*
			** Соединяет расшифрованную переменную среды со словом до него,
			** если между ними не было пробела;
			*/
			if (i != 0 && ft_strcmp(mass[i - 1], ";") != 0 &&
				ft_strcmp(mass[i - 1], "|") != 0 &&
				ft_strlen(space[i - 1]) == 0)
			{
				mass[i - 1] = ft_strjoin(mass[i - 1], mass[i]);
				j = i;
				while (mass[j + 1])
				{
					free(mass[j]);
					mass[j] = ft_strdup(mass[j + 1]);
					j++;
				}
				free(mass[j]);
				mass[j] = NULL;
			}
		}
		i++;
	}
}

/*
** Проверяет параметры в строке
*/

void		check_param(char *line, t_ptr *ptr)
{
	int		i;
	char 	**mass;
	char	**space;
	char	*dup_line;

	i = 0;
	init_struct_base(ptr);
	dup_line = ft_strdup(line);
	mass = line_space(line, ptr);
	space = line_space_counter(dup_line, ft_mass_len(mass), ptr);
	env_value(mass, ptr->is_env, space);
	while (mass[i])
	{
		if ((ft_strcmp(";", mass[i]) == 0) || (ft_strcmp("|", mass[i]) == 0))
		{
			ptr->base->flag_base = ft_realloc_mass(ptr->base->flag_base, mass[i]);
			i++;
		}
		else
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_command(&mass[i], ptr, space);
		}
	}
	ft_free_array(mass);
	ft_free_array(space);
}

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
		check_param(line, ptr);
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
	read_input(&ptr);
	return (0);
}
