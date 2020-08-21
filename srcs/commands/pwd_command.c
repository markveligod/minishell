/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:26:20 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/21 16:26:20 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	pwd_command(t_command *command)
{
	char		*p;
	char		*output;

	output = ft_strdup("");
	g_curr_err = "0";
	if (command->args[0] != NULL)
	{
		g_curr_err = "1";
		ft_putstr_fd("pwd: Too many arguments\n", 0);
		return ;
	}
	else
	{
		errno = 0;
		if ((p = getcwd(NULL, 10)) == NULL)
			errno_error(command->command, errno);
		else
		{
			free(output);
			output = ft_strdup(p);
			output = ft_strjoin(output, "\n");
		}
		free(p);
	}
	write_in_file(command, output);
}
