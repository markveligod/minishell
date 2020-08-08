/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:28:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/08 10:28:55 by leweathe         ###   ########.fr       */
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


void	fork_redirect(char *file_name, char *flag, char **mass)
{
	pid_t	cpid;
	pid_t	wpid;
	int		fd;
	int		status;
	int 	child[2];
	int		parent[2];

	pipe(child);
	pipe(parent);
	if (ft_strcmp(flag, ">") == 0)
		fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	else if (ft_strcmp(flag, ">>") == 0)
		fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0664);
	else if (ft_strcmp(flag, "<") == 0)
		fd = open(file_name, O_RDONLY);
	cpid = fork();
	if (ft_strcmp(flag, ">") == 0 || ft_strcmp(flag, ">>") == 0)
	{
		if (cpid == 0)
		{
			close(child[1]);
			close(parent[0]);
			child[0] = fd;
			//dup2(pipefd[1], STDOUT_FILENO);
			//close(child_to_parent[1]);
			//close(pipefd[1]);
			execve(mass[0], mass, NULL);
		}
		else
		{
			close(child[0]);
			close(parent[1]);
			wpid = waitpid(cpid, &status, WUNTRACED);
			//dup2(out, 1);
			//close(out);
		}
	}
	else if (ft_strcmp(flag, "<") == 0)
	{
		int in = dup(0);
		close(0);
		int ffd[2];
		char buf[11];
		pipe(ffd);
		if (cpid == 0)
		{
			dup2(ffd[0], 0);
			close(ffd[0]);
			close(ffd[1]);
			//while (read(0, buf, 10) > 0)
			//	write(ffd[0], buf, 10);
			execve(mass[0], mass, NULL);
		}
		else
		{
			close(ffd[0]);
			while (read(fd, buf, 10) > 0)
				write(ffd[1], buf, 10);
			wpid = waitpid(cpid, &status, WUNTRACED);
			close(ffd[1]);
			dup2(in, 0);
			close(in);
		}
	}
}

/*
** Запуск дочернего процесса  с учетом редиректов в файлы


void	fork_redirect(char *file_name, char *flag, char **mass)
{
	pid_t	cpid;
	pid_t	wpid;
	int		fd;
	int		status;
	int pipefd[2];

	int out = dup(1);
	int in = dup(0);
	close(1);
	close(0);
	if (ft_strcmp(flag, ">") == 0)
		fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	else if (ft_strcmp(flag, ">>") == 0)
		fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0664);
	else if (ft_strcmp(flag, "<") == 0)
		fd = open(file_name, O_RDONLY);
	cpid = fork();*/
	/*
	** _________________v1_____________________________
	*/
	/*
	if (ft_strcmp(flag, ">") == 0 || ft_strcmp(flag, ">>") == 0)
	{
		pipe(pipefd);
		pipefd[1] = dup(fd);
		if (cpid == 0)
		{
			dup2(pipefd[1], STDOUT_FILENO);
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
	}
	else if (ft_strcmp(flag, "<") == 0)
	{
		char buf[2];
		pipe(pipefd);
		if (cpid == 0)
		{
			close(pipefd[1]);
			//pipefd[0] = fd;
			//close(pipefd[0]);
			//close(fd);
			//STDIN_FILENO = dup(pipefd[0]);
			//dup2(pipefd[0], STDIN_FILENO);
			while (read(pipefd[0], buf, 1) > 0)
				write(STDIN_FILENO, buf, 1);
			close(pipefd[0]);
			execve(mass[0], mass, NULL);
		}
		else
		{
			close(pipefd[0]);
			//pipefd[1] = fd;
			//dup2(fd, pipefd[1]);
			while (read(fd, buf, 1) > 0)
				write(pipefd[1], buf, 1);
			close(pipefd[1]);
			close(fd);
			wpid = waitpid(cpid, &status, WUNTRACED);
			dup2(in, STDIN_FILENO);
			close(in);
		}
		close(fd);
	}*/
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
//}
