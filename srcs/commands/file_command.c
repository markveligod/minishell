/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:48:27 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/09 12:07:59 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

char		*relative_path(char *command, char **env)
{

}

int			check_stat(t_command *command, char *filename, int name_flag)
{
	int fd;
	int flag;
	struct stat buff;
	
	flag = 0;
	if((fd = open(filename, O_RDONLY)) == (-1))
	{
		if (name_flag == 1)
		{
			g_curr_err = "127";
			errno = -5;
		}
		else
			g_curr_err = "1";
		errno_error(command->command, errno);
		return (flag = (-1));
	}
	fstat(fd, &buff);
	if ((buff.st_mode & S_IRWXU) == (S_IXUSR) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR + S_IWUSR) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR + S_IRUSR) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR + S_IRUSR + S_IWUSR))
		flag = 1;
	close(fd);
	return (flag);
}
