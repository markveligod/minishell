/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:23:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/07 13:24:01 by ckakuna          ###   ########.fr       */
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

void	get_path(char **mass, int *flag)
{
	char	*temp;

	*flag = 0;
	if (ft_one_of_them(mass[0][0], "/."))
		*flag = 0;
	else if (!(mass[0][0] == '/' && mass[0][1] == 'b' && mass[0][2] == 'i' && mass[0][3] == 'n'
		&& mass[0][4] == '/'))
	{
		temp = ft_strdup(mass[0]);
		free(mass[0]);
		mass[0] = ftstrjoin("/bin/", temp);
		free(temp);
		*flag = 1;
	}
}

void	external_command(t_command *command, char **env)
{
	int			i;
	char		**mass;
	int			name_flag;
	int			flag;

	mass = create_args(command);
	get_path(mass, &name_flag);
	g_flag = 1;
	g_curr_err = "0";
	flag = check_stat(command, mass[0], name_flag);
	run_forks(flag, command, mass);
	ft_free_array(mass);
}
