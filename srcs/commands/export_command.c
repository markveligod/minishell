/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:47:47 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 10:37:06 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Проверяем аргумент в массиве env
*/

int			check_args(char **env, char *value)
{
	int		i;
	char	*temp;
	
	i = 0;
	while (value[i] != '=')
		i++;
	value[i] = '\0';
	temp = ft_strdup(value);
	value[i] = '=';
	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], temp) == 0)
		{
			free(temp);
			return (1);
		}
		i++;
	}
	free(temp);
	return (0);
}

/*
** Меняем существующий аргумент
*/

char		**change_env(char **env, char *value)
{
	int		i;
	char	*temp_name;
	char	*temp_value;

	i = 0;
	while (value[i] != '=')
		i++;
	value[i] = '\0';
	temp_name = ft_strdup(value);
	i++;
	temp_value = ft_strdup(&value[i]);
	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], temp_name) == 0)
		{
			i++;
			free(env[i]);
			env[i] = NULL;
			env[i] = ft_strdup(temp_value);
			break ;
		}
		i++;
	}
	free(temp_name);
	free(temp_value);
	return (env);
}

/*
** 	Добавляем аргумент в конец env
*/

char		**add_args(char **env, char *value)
{
	int		i;
	char	*temp_name;
	char	*temp_value;
	
	i = 0;
	while (value[i] != '=')
		i++;
	value[i] = '\0';
	temp_name = ft_strdup(value);
	i++;
	temp_value = ft_strdup(&value[i]);
	env = ft_realloc_mass(env, temp_name);
	env = ft_realloc_mass(env, temp_value);
	free(temp_name);
	free(temp_value);
	return (env);
}

/*
** Проверка на правильный аргумент
*/

void		export_command(t_ptr *ptr, t_command *t_command)
{
	int i;
	int j;

	i = 0;
	while (t_command->args[i])
	{
		j = 0;
		while (t_command->args[i][j] != '=')
			j++;
		if (t_command->args[i][j] != '\0')
		{
			if (check_args(ptr->base->is_env, t_command->args[i]) == 1)
				ptr->base->is_env = change_env(ptr->base->is_env, t_command->args[i]);
			else
				ptr->base->is_env = add_args(ptr->base->is_env, t_command->args[i]);
		}
		i++;
	}
}
