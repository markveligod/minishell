/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:26:24 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 12:26:26 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Проверяем аргумент в массиве env
*/

int			export_check_args(char **env, char *value)
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

char		**export_change_env(char **env, char *value)
{
	int		i;
	char	*temp_name;
	char	*temp_value;

	i = 0;
	while (value[i] != '=')
		i++;
	value[i] = '\0';
	temp_name = ft_strdup(value);
	temp_value = ft_strdup(&value[++i]);
	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], temp_name) == 0)
		{
			free(env[++i]);
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

char		**export_add_args(char **env, char *value)
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

int			export_equal_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '=')
			return (1);
		i++;
	}
	return (0);
}

void		export_com_here(t_ptr *ptr, t_command *command, int i)
{
	int		j;

	j = 0;
	while (command->args[i][j] && command->args[i][j] != '=')
		j++;
	if (command->args[i][j] != '\0')
	{
		if (export_check_args(ptr->is_env, command->args[i]) == 1)
			ptr->is_env = export_change_env(ptr->is_env, command->args[i]);
		else
			ptr->is_env = export_add_args(ptr->is_env, command->args[i]);
	}
	else
		ptr->is_export = ft_realloc_mass(ptr->is_export, command->args[i]);
}
