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
	int			i;
	int			j;
	int			count;
	int			flag;
	int			*mass_red;
	char		***mass;
	t_command	*com;
	t_command	*new;
	t_command	**com_mass;
	
	if (ptr->command == NULL)
		return;
	com = ptr->command;
	while (com)
	{
		if (com->base == '|')
		{
			count = 1;
			new = com;
			while (new->base == '|')
			{
				count++;
				new = new->next;
			}
			mass = (char ***)malloc(sizeof(char **) * count);
			com_mass = (t_command **)malloc(sizeof(t_command *) * count);
			mass_red = (int *)malloc(sizeof(int) * (count));
			i = 0;
			j = 0;
			flag = 1;
			while (flag == 1)
			{
				if (if_internal_command(com, ptr) == 0)
					mass[i] = external_mass(com, ptr->is_env);
				else
				{
					mass[i] = NULL;
					com_mass[j++] = com;
				}
				mass_red[i++] = get_fd(com);
				flag = 0;
				if (com->base == '|')
					flag = 1;
				com = com->next;
			}
			process_fork(mass, ptr->is_env, count, mass_red, com_mass, ptr);
		}
		else
		{
			do_command(com, ptr);
			com = com->next;
		}
	}
}

void process_fork(char ***mass, char **env, int size, int *mass_red, t_command **com_mass, t_ptr *ptr)
{
	pid_t pid;
	int fd[2];
	int status;
	int i;
	int prev_pipe;

	i = 0;
	int j = 0;
	prev_pipe = dup(STDIN_FILENO); //0
	while (i < size)
	{
		if (i < size - 1)
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
			if (mass[i] != NULL)
				execve(mass[i][0], mass[i], NULL);
			else
				do_command(com_mass[j++], ptr);
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
	return;
}
