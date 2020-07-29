/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 08:37:11 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 12:04:01 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Функция для пересоздания массива переменных окружения env
*/

void		unset_command(t_ptr *ptr, t_command *t_command)
{
	int		i;
	int		j;
	char	*temp;
	char	**new_env;
	
	if (t_command->args[0] == NULL)
		return ;
	i = 0;
	new_env = (char **)malloc(sizeof(char *) * 1);
	new_env[0] = NULL;
	while (ptr->is_env[i])
	{
		j = 0;
		while (t_command->args[j])
		{
			if (ft_strcmp(ptr->is_env[i], t_command->args[j]) == 0)
				break ;
			j++;
		}
		if (t_command->args[j] != NULL)
		{
			i += 2;
			continue ;
		}
		else
		{
			temp = ft_strdup(ptr->is_env[i]);
			new_env = ft_realloc_mass(new_env, temp);
			free(temp);
			i++;
			temp = ft_strdup(ptr->is_env[i]);
			new_env = ft_realloc_mass(new_env, temp);
			free(temp);
			i++;
		}
	}
	ft_free_array(ptr->is_env);
	ptr->is_env = NULL;
	ptr->is_env = new_env;
}