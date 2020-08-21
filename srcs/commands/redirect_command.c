/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:26:07 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/21 16:28:57 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	run_child(t_command *command, int *fd)
{
	char *line;

	signal(SIGINT, exit);
	signal(SIGQUIT, exit);
	dup2(get_fd(command), fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	while (get_next_line(&line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(fd[1]);
	exit(1);
}

void	redirect_command(t_command *command)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	g_signal = 2;
	pid = fork();
	if (pid < 0)
		return ;
	else if (pid == 0)
		run_child(command, fd);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		close(fd[1]);
		close(fd[0]);
		g_signal = 0;
	}
}
