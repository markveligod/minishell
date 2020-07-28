/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:06:07 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/28 15:06:09 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Проверяет на наличие -n флагов
*/

int			check_nnn(char **str, char **spaces, int *flag)
{
	int		i;

	i = 0;
	*flag = 0;
	while (str[i])
	{
		if (ft_strcmp("-n", str[i]) == 0 && ft_strlen(spaces[i]) != 0)
		{
			*flag = 1;
			i++;
		}
		else
			break ;
	}
	return (i);
}

void		echo_command(t_command *command)
{
	char	*line;
	char	*word;
	int		flag;
	int		i;

	i = 0;
	i += check_nnn(command->args, command->spaces, &flag);
	line = ft_strdup("");
	while (command->args[i])
	{
		word = ftstrjoin(command->args[i], command->spaces[i]);
		line = ft_strjoin(line, word);
		free(word);
		i++;
	}
	if (flag == 0)
		line = ft_strjoin(line, "\n");
	write_in_file(command, line);
}
