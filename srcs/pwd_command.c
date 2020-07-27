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

#include "../minish.h"
#include <errno.h>
#include <string.h>

void	pwd_command(char **args)
{
	char		*p;
	errno_t		error_num;

	if (args[0] != NULL)
		printf("pwd: Too many arguments\n");
	else
	{
		errno = 0;
		if ((p = getcwd(NULL, 10)) == NULL)
		{
			error_num = errno;
			printf("pwd: %s\n", (char *)strerror(error_num));
		}
		else
		{
			printf("%s\n", p);
			free(p);
		}
	}
}
