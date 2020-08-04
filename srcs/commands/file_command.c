/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:48:27 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/04 13:51:03 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void		file_command(t_command *command)
{
	struct stat *buff;
	errno_t error_num;
	int fd;
	pid_t pid;
	pid_t wpid;
	int status;
	char **mass;
	int i;

	errno = 0;
	if (!(mass = (char **)malloc(sizeof(char *))))
		return ;
	mass[0] = NULL;
	mass = ft_realloc_mass(mass, command->command);
	i = 0;
	if (command->args)
		while (command->args[i])
			mass = ft_realloc_mass(mass, command->args[i++]);
	if((fd = open(&command->command[2], O_RDONLY)) == (-1))
	{
		g_curr_err = "1";
		errno_error(command->command, errno);
		return ;
	}
	fstat(fd, buff);
	if ((buff->st_mode & S_IRWXG) == ((S_IRGRP + S_IWGRP + S_IXGRP) || (S_IRGRP + S_IXGRP) || (S_IWGRP + S_IXGRP)))
	{
		pid = fork();
		if (pid == 0)
			execve(mass[0], mass, NULL);
		else if (pid == -1)
			errno_error(command->command, errno);
		else
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	ft_free_array(mass);
	g_curr_err = "0";
}