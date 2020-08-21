/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_fork_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:28:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/21 16:15:44 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	run_forks(int flag, t_command *command, char **mass)
{
	int i;

	i = 0;
	if (flag == 1 && command->filename[i] != NULL)
		while (command->filename[i])
		{
			fork_redirect(command->filename[i], command->flag_v[i], mass);
			i++;
		}
	else if (flag == 1 && command->filename[i] == NULL)
		fork_run(command, mass);
	else
	{
		g_curr_err = "1";
		if (flag == 0)
		{
			errno = 13;
			errno_error(command->command, errno);
		}
	}
}

/*
** Запуск дочернего процесса без редиректов
*/

void	fork_run(t_command *command, char **mass)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	errno = 0;
	pid = fork();
	if (pid == 0)
		execve(mass[0], mass, NULL);
	else if (pid == -1)
		errno_error(command->command, errno);
	else
		wpid = waitpid(pid, &status, WUNTRACED);
	kill(pid, SIGKILL);
}

/*
** Запуск дочернего процесса с учетом редиректа
*/

void	right_arrow(pid_t cpid, int *pipefd, char **mass, int fd)
{
	int status;

	close(pipefd[1]);
	pipefd[1] = fd;
	if (cpid == 0)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(mass[0], mass, NULL);
	}
	else
	{
		close(pipefd[0]);
		waitpid(cpid, &status, WUNTRACED);
	}
}

void	left_arrow(pid_t cpid, int *pipefd, char **mass, int fd)
{
	int status;

	close(pipefd[0]);
	pipefd[0] = fd;
	if (cpid == 0)
	{
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(mass[0], mass, NULL);
	}
	else
	{
		close(pipefd[1]);
		waitpid(cpid, &status, WUNTRACED);
	}
}

void	fork_redirect(char *file_name, char *flag, char **mass)
{
	pid_t	cpid;
	int		fd;
	int		pipefd[2];

	if (ft_strcmp(flag, ">") == 0)
		fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	else if (ft_strcmp(flag, ">>") == 0)
		fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0664);
	else if (ft_strcmp(flag, "<") == 0)
		fd = open(file_name, O_RDONLY);
	cpid = fork();
	pipe(pipefd);
	if (ft_strcmp(flag, ">") == 0 || ft_strcmp(flag, ">>") == 0)
		right_arrow(cpid, pipefd, mass, fd);
	else if (ft_strcmp(flag, "<") == 0)
		left_arrow(cpid, pipefd, mass, fd);
}
