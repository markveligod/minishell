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

#include "../minish.h"
#include <errno.h>
#include <string.h>

void cd_command(char **path)
{
	errno = 0;
	if (ft_mass_len(path) != 1 && ft_mass_len(path) != 0)
	{
		printf("cd: Too many arguments\n");
		return ;
	}
	if (ft_mass_len(path) == 0)
		path[0] = ft_strdup("/");
	if (chdir(path[0]) != 0)
	{
		errno_t error_num = errno;
		printf("cd: %s\n", (char *)strerror(error_num));
	}
}
