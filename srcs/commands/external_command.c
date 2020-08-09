/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:23:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/09 12:07:42 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

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
	char	*temp;

	*name_flag = 0;
	if (mass[0][0] == '/')
		*name_flag = 0;
	else if (ft_one_of_them('/', mass[0]))
		mass[0] = relative_path(mass[0], env);
	else
	{
		command_path(mass, env);
		*name_flag = 1;
	}
}

void	external_command(t_command *command, char **env)
{
	int			i;
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
