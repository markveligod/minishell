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
#include <errno.h>
#include <string.h>

void	pwd_command(t_command *command)
{
	char		*p;
	errno_t		error_num;
	char		*output;

	if (command->args[0] != NULL)
		output = ft_strdup("pwd: Too many arguments");
	else
	{
		errno = 0;
		if ((p = getcwd(NULL, 10)) == NULL)
		{
			error_num = errno;
			output = ftstrjoin("pwd: ", (char *)strerror(error_num));
		}
		else
		{
			output = ft_strdup(p);
			free(p);
		}
	}
	output = ft_strjoin(output, "\n");
	printf("%s", output);
}
