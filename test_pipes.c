/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:59:28 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/17 19:58:39 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	test_pipes(t_ptr *ptr)
{
	int i;
	int j;
	int k;
	char **fd;
	char **flag;
	int ct;
	char **base;
	int c;
	/*
	** Start test commands	
	*/
	if (ptr->command != NULL)
	{
		ct = 1;
		t_command *com;
		com = ptr->command;
		while (com)
		{
			if (com->base == '|')
			{
				t_command *new;
				int count;
				count = 1;
				new = com;
				new = new->next;
				while (new->base == '|')
				{
					count++;
					new = new->next;
				}
				count++;
				char ***mass;
				mass = (char ***)malloc(sizeof(char **) * (count + 1));
				mass[count] = NULL;
				i = 0;
				while (com->base == '|')
				{
					mass[i] = external_mass(com, ptr->is_env);
					com = com->next;
					i++;
				}
				mass[i] = external_mass(com, ptr->is_env);
				com = com->next;
				int *mass_red;
				mass_red = (int *)malloc(sizeof(int) * (count));
				i = 0;
				while (i < count)
					mass_red[i++] = 0;
				process_fork(mass, ptr->is_env, count - 1, mass_red);
			}
			else
			{
				do_command(com, ptr);
				com = com->next;
			}
			ct++;
		}
	}
}

void process_fork(char ***mass, char **env, int size, int *mass_red)
{
	pid_t pid;
	int fd[2];
	int status;
	int i;
	int prev_pipe;

	i = 0;
	prev_pipe = dup(STDIN_FILENO); //0
	while (i < size)
	{
		pipe(fd); //fd[0] fd[1]
		pid = fork();
		if (pid < 0)
		{
			perror("FORK ERROR\n");
		}
		else if (pid == 0) //child
		{
			if (prev_pipe != STDIN_FILENO)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (mass_red[i] != 0)
				fd[1] = dup(mass_red[i]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			execve(mass[i][0], mass[i], NULL);
			exit(1);
		}
		else //parent
		{
			waitpid(pid, &status, WUNTRACED);
			close(prev_pipe);
			close(fd[1]);
			prev_pipe = fd[0];
			i++;
		}
	}
	pid = fork();
	if (pid < 0)
	{
		perror("FORK ERROR\n");
	}
	else if (pid == 0) //child last command
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
		execve(mass[i][0], mass[i], env);
		exit(1);
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return;
}
