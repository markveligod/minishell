/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:47:03 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 07:54:36 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Функция для печати переменных окружения
*/

void		env_command(char **env, t_command *command)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strdup("");
	if (command->args[0] != NULL)
		ft_putstr_fd("pwd: Too many arguments\n", 0);
	else
		while (env[i])
		{
			line = ft_strjoin(line, env[i++]);
			line = ft_strjoin(line, "=");
			line = ft_strjoin(line, env[i++]);
			line = ft_strjoin(line, "\n");
		}
	write_in_file(command, line);
}