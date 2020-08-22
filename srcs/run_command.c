/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:59:28 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 13:07:22 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	run_commands(t_ptr *ptr)
{
	int			count;
	t_command	*com;

	com = ptr->command;
	if (com == NULL)
		return ;
	while (com)
	{
		if (com->base == '|')
		{
			count = size_pipe_in_line(com);
			init_mass_command(ptr, count);
			com = put_param_in_mass(com, ptr);
			pipe_commands(ptr, count);
			clear_mass_com(ptr, count);
		}
		else
		{
			do_command(com, ptr);
			com = com->next;
		}
	}
}

void	pipe_redirect_fork(int file, char **mass, t_command *com_mass,
t_ptr *ptr)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	pipe(fd);
	pid = fork();
	if (pid < 0)
	{
		errno_error("FORK", errno);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		dup2(file, fd[1]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		if (mass != NULL)
			execve(mass[0], mass, ptr->is_env);
		else
			do_command(com_mass, ptr);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, WUNTRACED);
}

void	child_pipe_command(int prev_pipe, t_ptr *ptr, int i, int *fd)
{
	if (prev_pipe != STDIN_FILENO)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (ptr->mass_red[i] != 0)
		pipe_redirect_fork(ptr->mass_red[i], ptr->mass[i],
		ptr->com_mass[i], ptr);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (ptr->mass[i] != NULL)
		execve(ptr->mass[i][0], ptr->mass[i], NULL);
	else
		do_command(ptr->com_mass[i], ptr);
	exit(EXIT_SUCCESS);
}

void	pipe_commands(t_ptr *ptr, int size)
{
	pid_t	pid;
	int		fd[2];
	int		status;
	int		i;
	int		prev_pipe;

	i = 0;
	prev_pipe = dup(STDIN_FILENO);
	while (i < size)
	{
		if (i < size - 1)
			pipe(fd);
		pid = fork();
		if (pid < 0)
			errno_error("FORK", errno);
		else if (pid == 0)
			child_pipe_command(prev_pipe, ptr, i, fd);
		else
			waitpid(pid, &status, WUNTRACED);
		close(prev_pipe);
		close(fd[1]);
		prev_pipe = fd[0];
		i++;
	}
}
