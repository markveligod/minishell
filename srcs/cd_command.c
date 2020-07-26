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

void do_cd(t_cd *cd)
{
	errno = 0;
	if (chdir(cd->path) != 0)
	{
		errno_t error_num = errno;
		printf("%s\n", (char *)strerror(error_num));
	}
}
