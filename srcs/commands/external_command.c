/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:23:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/27 22:23:07 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"
#include <errno.h>
#include <string.h>

int		external_command(t_command *command)
{
	int			i;
	pid_t		pid;
	pid_t		wpid;
	errno_t		error_num;
	char		**mass;
	int			status;

	i = 0;
	errno = 0;
	if (!(mass = (char **)malloc(sizeof(char *))))
		return (0);
	mass[0] = NULL;
	mass = ft_realloc_mass(mass, command->command);
	while (command->args[i])
		mass = ft_realloc_mass(mass, command->args[i++]);
	mass[0] = ftstrjoin("/bin/", mass[0]);
	pid = fork();
	if (pid == 0)
		execve(mass[0], mass, NULL);
	else if (pid == -1)
	{
		error_num = errno;
		printf("ERROR %s\n", (char *)strerror(error_num));
	}
	else
		wpid = waitpid(pid, &status, WUNTRACED);
	ft_free_array(mass);
	return (1);
}
