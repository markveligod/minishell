/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:32:33 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/22 13:12:15 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int			size_pipe_in_line(t_command *com)
{
	int			size;
	t_command	*new;

	size = 1;
	new = com;
	while (new->base == '|')
	{
		size++;
		new = new->next;
	}
	return (size);
}

void		init_mass_command(t_ptr *ptr, int count)
{
	ptr->mass = (char ***)malloc(sizeof(char **) * count);
	ptr->com_mass = (t_command **)malloc(sizeof(t_command *) * count);
	ptr->mass_red = (int *)malloc(sizeof(int) * (count));
	if (!ptr->mass || !ptr->com_mass || !ptr->mass_red)
	{
		errno_error("Malloc fail", errno);
		exit(EXIT_FAILURE);
	}
}

t_command	*put_param_in_mass(t_command *com, t_ptr *ptr)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (flag == 1)
	{
		if (if_internal_command(com) == 0)
		{
			ptr->mass[i] = external_mass(com, ptr->is_env);
			ptr->com_mass[i] = NULL;
		}
		else
		{
			ptr->mass[i] = NULL;
			ptr->com_mass[i] = com;
		}
		ptr->mass_red[i++] = get_fd(com);
		flag = 0;
		if (com->base == '|')
			flag = 1;
		com = com->next;
	}
	return (com);
}

void		clear_mass_com(t_ptr *ptr, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (ptr->mass[i] != NULL)
			ft_free_array(ptr->mass[i]);
		else
			free(ptr->mass[i]);
		i++;
	}
	free(ptr->mass);
	free(ptr->com_mass);
	free(ptr->mass_red);
}
