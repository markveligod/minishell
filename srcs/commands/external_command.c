/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:23:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/02 07:27:44 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

int		check_path(char *line)
{
	return (line[0] == '/' && line[1] == 'b' && line[2] == 'i' && line[3] == 'n'
	&& line[4] == '/');
}

int		external_command(t_command *command)
{
	int			i;
	pid_t		pid;
	pid_t		wpid;
	errno_t		error_num;
	char		**mass;
	int			status;
	char		*temp;

	i = 0;
	errno = 0;
	if (!(mass = (char **)malloc(sizeof(char *))))
		return (0);
	mass[0] = NULL;
	mass = ft_realloc_mass(mass, command->command);
	while (command->args[i])
		mass = ft_realloc_mass(mass, command->args[i++]);
	temp = ft_strdup(mass[0]);
	free(mass[0]);
	if (check_path(temp))
		mass[0] = ft_strdup(temp);
	else
		mass[0] = ftstrjoin("/bin/", temp);
	free(temp);
	pid = fork();
	if (pid == 0)
		execve(mass[0], mass, NULL);
	else if (pid == -1)
		errno_error(command->command, errno);
	else
		wpid = waitpid(pid, &status, WUNTRACED);
	ft_free_array(mass);
	return (1);
}
