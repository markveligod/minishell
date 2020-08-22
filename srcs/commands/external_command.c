/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:23:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 13:10:57 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

char	*command_path(char *name, char **env)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	while (env[i] && ft_strcmp(env[i], "PATH") != 0)
		i++;
	if (env[i] && env[++i])
	{
		path = ft_split(env[i], ':');
		j = -1;
		while (path[++j])
		{
			path[j] = ft_strjoin(path[j], "/");
			path[j] = ft_strjoin(path[j], name);
			if (open(path[j], O_RDONLY) != -1)
			{
				free(name);
				name = ft_strdup(path[j]);
				break ;
			}
		}
		ft_free_array(path);
	}
	return (name);
}

char	**create_args(t_command *command)
{
	char	**mass;
	int		i;

	i = 0;
	if (!(mass = (char **)malloc(sizeof(char *))))
		return (NULL);
	mass[0] = NULL;
	mass = ft_realloc_mass(mass, command->command);
	while (command->args[i])
		mass = ft_realloc_mass(mass, command->args[i++]);
	return (mass);
}

void	get_path(char **mass, int *name_flag, char **env)
{
	*name_flag = 0;
	if (mass[0][0] == '/')
		*name_flag = 0;
	else if (ft_one_of_them('/', mass[0]))
		mass[0] = relative_path(mass[0]);
	else
	{
		mass[0] = command_path(mass[0], env);
		*name_flag = 1;
	}
}

void	external_command(t_command *command, char **env)
{
	char		**mass;
	int			name_flag;
	int			flag;

	mass = create_args(command);
	get_path(mass, &name_flag, env);
	g_flag = 1;
	g_curr_err = "0";
	flag = check_stat(command, mass[0], name_flag);
	run_forks(flag, command, mass);
	ft_free_array(mass);
}

char	**external_mass(t_command *command, char **env)
{
	char	**mass;
	int		name_flag;
	int		flag;

	mass = create_args(command);
	get_path(mass, &name_flag, env);
	g_flag = 1;
	g_curr_err = "0";
	flag = check_stat(command, mass[0], name_flag);
	return (mass);
}
