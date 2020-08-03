/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:06:07 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/03 10:57:18 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Проверяет на наличие -n флагов
*/

int			check_nnn(char **str, int *flag)
{
	int		i;

	i = 0;
	*flag = 0;
	while (str[i])
	{
		if (ft_strcmp("-n", str[i]) == 0)
		{
			*flag = 1;
			i++;
		}
		else
			break ;
	}
	return (i);
}

/*
** Получаем из env переменную окружения
*/

char		*get_dollar(char *arg, char **env)
{
	int i;
	
	if (arg[0] == '?' && arg[1] == '\0')
		return (g_curr_err);
	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], arg) == 0)
			return (env[++i]);
		i++;
	}
	return (NULL);
}

void		echo_command(t_command *command, t_ptr *ptr)
{
	char	*line;
	char	*word;
	int		flag;
	int		i;

	i = 0;
	i += check_nnn(command->args, &flag);
	line = ft_strdup("");
	while (command->args[i])
	{
		if (command->args[i][0] == '$')
			line = ft_strjoin(line, get_dollar(&command->args[i][1], ptr->is_env));
		else
		{
			word = ftstrjoin(command->args[i], command->spaces[i]);
			line = ft_strjoin(line, word);
			free(word);
		}
		i++;
	}
	if (flag == 0)
		line = ft_strjoin(line, "\n");
	write_in_file(command, line);
	g_curr_err = "0";
}
