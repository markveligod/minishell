/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:34:01 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/21 15:34:03 by ckakuna          ###   ########.fr       */
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

void		echo_command(t_command *command)
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
		word = ftstrjoin(command->args[i], command->spaces[i]);
		line = ft_strjoin(line, word);
		free(word);
		i++;
	}
	if (flag == 0)
		line = ft_strjoin(line, "\n");
	write_in_file(command, line);
}
