/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:21:42 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/27 10:21:44 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	pwd_command(t_command *command)
{
	char		*p;
	errno_t		error_num;
	char		*output;

	output = ft_strdup("");
	if (command->args[0] != NULL)
		ft_putstr_fd("pwd: Too many arguments\n", 0);
	else
	{
		errno = 0;
		if ((p = getcwd(NULL, 10)) == NULL)
			errno_error(command->command, errno);
		else
		{
			output = ft_strdup(p);
			output = ft_strjoin(output, "\n");
			free(p);
		}
	}
	write_in_file(command, output);
}
