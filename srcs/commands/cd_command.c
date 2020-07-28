/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:25:35 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/26 13:25:37 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"
#include <errno.h>
#include <string.h>

void cd_command(t_command *command)
{
	errno_t		error_num;
	int			len;

	errno = 0;
	len = ft_mass_len(command->args);
	if (len != 1 && len != 0)
	{
		printf("cd: Too many arguments\n");
		return ;
	}
	if (len == 0)
		command->args[0] = ft_strdup("/");
	if (chdir(command->args[0]) != 0)
	{
		error_num = errno;
		printf("cd: %s\n", (char *)strerror(error_num));
	}
}
