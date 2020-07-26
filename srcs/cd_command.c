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

void do_cd(char **path)
{
	/*errno = 0;
	if (chdir(path[0]) != 0)
	{
		errno_t error_num = errno;
		printf("%s\n", (char *)strerror(error_num));
	}*/
	char s[100];
	printf("%s\n", path[0]);
	printf("%s\n", getcwd(s, 100));
	chdir("..");
	printf("%s\n", getcwd(s, 100));
}
