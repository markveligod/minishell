/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:23:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/03 13:32:08 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

int		check_path(char *line)
{
	return (line[0] == '/' && line[1] == 'b' && line[2] == 'i' && line[3] == 'n'
	&& line[4] == '/');
}

void	fork_exec(char *file_name, char *flag, char **mass)
{
	pid_t	cpid;
	pid_t	wpid;
	int		fd;
	int		status;
	int pipefd[2];

	int out = dup(1);
	close(1);
	if (ft_strcmp(flag, ">") == 0)
		fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	else if (ft_strcmp(flag, ">>") == 0)
		fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0664);
	cpid = fork();
	/*
	** _________________v1_____________________________
	*/
	pipe(pipefd);
	pipefd[1] = dup(fd);
	if (cpid == 0)
	{
		dup2(pipefd[1], 0);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(mass[0], mass, NULL);
	}
	else
	{
		wpid = waitpid(cpid, &status, WUNTRACED);
		dup2(out, 1);
		close(out);
	}
	/*
	** ________________________________________________
	*/

	/*
	** ________________v2______________________________

	if (cpid == 0)
	{
		dup2(fd, 1);
		execve(mass[0], mass, NULL);
	}
	else if (cpid > 0)
	{
		wpid = waitpid(cpid, &status, WUNTRACED);
		dup2(out, 1);
		close(out);
	}

	** ________________________________________________
	*/
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
	g_flag = 1;
	if (command->filename[0] != NULL)
	{
		i = 0;
		while (command->filename[i])
		{
			fork_exec(command->filename[i], command->flag_v[i], mass);
			i++;
		}
	}
	else
	{
		pid = fork();
		if (pid == 0)
			execve(mass[0], mass, NULL);
		else if (pid == -1)
			errno_error(command->command, errno);
		else
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	ft_free_array(mass);
	kill(pid, SIGKILL);
	return (1);
}
