/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:59:28 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/19 11:48:42 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	run_commands(t_ptr *ptr)
{
	int			i;
	int			j;
	int			count;
	int			flag;
	int			*mass_red;
	char		***mass;
	t_command	*new;
	t_command	**com_mass;
	t_command	*com;

	com = ptr->command;
	if (com == NULL)
		return;
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
				{
					mass[i] = external_mass(com, ptr->is_env);
					com_mass[i] = NULL;
				}
				else
				{
					mass[i] = NULL;
					com_mass[i] = com;
				}
				mass_red[i++] = get_fd(com);
				flag = 0;
				if (com->base == '|')
					flag = 1;
				com = com->next;
			}
			pipe_commands(mass, ptr, count, mass_red, com_mass);
			i = 0;
			while (i < count)
				if (mass[i++])
					ft_free_array(mass[i]);
			free(mass);
			free(com_mass);
			free(mass_red);
		}
		else
		{
			do_command(com, ptr);
			com = com->next;
		}
	}
}

void pipe_redirect_fork(int file, char **mass, t_command *com_mass, t_ptr *ptr)
{
    pid_t pid;
    int fd[2];
    int status;

    pipe(fd);
    pid = fork();
    if (pid < 0)
    {
        perror("FORK ERROR\n");
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
    {
        waitpid(pid, &status, WUNTRACED);
        return ;
    }
    
}

void pipe_commands(char ***mass, t_ptr *ptr, int size, int *mass_red, t_command **com_mass)
{
	pid_t pid;
	int fd[2];
	int status;
	int i;
	int prev_pipe;

	i = 0;
	prev_pipe = dup(STDIN_FILENO);
	while (i < size)
	{
		if (i < size - 1)
			pipe(fd);
		pid = fork();
		if (pid < 0)
		{
			perror("FORK ERROR\n");
		}
		else if (pid == 0)
		{
			if (prev_pipe != STDIN_FILENO)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (mass_red[i] != 0)
				pipe_redirect_fork(mass_red[i], mass[i], com_mass[i], ptr);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			if (mass[i] != NULL)
				execve(mass[i][0], mass[i], NULL);
			else
				do_command(com_mass[i], ptr);
			exit(1);
		}
		else
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
