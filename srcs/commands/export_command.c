/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:38:06 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/21 15:44:09 by ckakuna          ###   ########.fr       */
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

int			equal_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '=')
			return (1);
		i++;		
	}
	return (0);
}

void		print_export(char **is_export)
{
	int i;

	i = 0;
	while (is_export[i] != NULL)
	{
		ft_putstr(is_export[i]);
		ft_putstr("=' '\n");
		i++;
	}
}

void        com_here(t_ptr *ptr, t_command *t_command, int i)
{
    int j;
    
    j = 0;
	while (t_command->args[i][j] && t_command->args[i][j] != '=')
		j++;
	if (t_command->args[i][j] != '\0')
	{
		if (check_args(ptr->is_env, t_command->args[i]) == 1)
			ptr->is_env = change_env(ptr->is_env, t_command->args[i]);
		else
			ptr->is_env = add_args(ptr->is_env, t_command->args[i]);
	}
	else
		ptr->is_export = ft_realloc_mass(ptr->is_export, t_command->args[i]);
}

void		export_command(t_ptr *ptr, t_command *t_command)
{
	int i;

	i = 0;
	if (t_command->args[0] == NULL)
	{
		env_command(ptr->is_env, t_command);
		print_export(ptr->is_export);
	}
	else
		if ((equal_args(t_command->args)) == 1)
		{
			g_curr_err = "1";
			errno_error(t_command->command, 1);
			return ;
		}
	while (t_command->args[i])
    {
        com_here(ptr, t_command, i);
        i++;
    }
	g_curr_err = "0";
}
