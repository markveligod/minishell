/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:48:20 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 13:08:23 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

char		**create_new_env(t_ptr *ptr, t_command *command)
{
	int		i;
	int		j;
	char	**new_env;

	if (!(new_env = (char **)malloc(sizeof(char *) * 1)))
		error("Allocation problem!", ptr);
	new_env[0] = NULL;
	i = 0;
	while (ptr->is_env[i])
	{
		j = -1;
		while (command->args[++j])
			if (ft_strcmp(ptr->is_env[i], command->args[j]) == 0)
				break ;
		if (command->args[j] != NULL)
			i += 2;
		else
		{
			new_env = ft_realloc_mass(new_env, ptr->is_env[i++]);
			new_env = ft_realloc_mass(new_env, ptr->is_env[i++]);
		}
	}
	return (new_env);
}

/*
** Функция для пересоздания массива переменных окружения env
*/

void		unset_command(t_ptr *ptr, t_command *command)
{
	char	**new_env;

	if (command->args[0] == NULL)
	{
		g_curr_err = "1";
		ft_putstr("unset: not enough arguments");
		return ;
	}
	new_env = create_new_env(ptr, command);
	ft_free_array(ptr->is_env);
	ptr->is_env = NULL;
	ptr->is_env = new_env;
	g_curr_err = "0";
}
