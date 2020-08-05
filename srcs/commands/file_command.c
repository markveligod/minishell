/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:48:27 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/05 11:38:44 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

char		*get_path_filename(char *command, char **env)
{
	char *path;
	char *temp;
	int i;
	int size;

	i = 0;
	while (ft_strcmp(env[i], "PWD") != 0)
		i++;
	temp = ft_strdup(env[++i]);
	size = ft_strlen(temp);
	i = 0;
	while (command[i])
	{
		if (command[i] == '.' && command[i + 1] == '.' && command[i + 2] == '/')
		{
			while (temp[--size] != '/')
				NULL ;
			temp[size] = '\0';
			i += 3;
			continue ;
		}
		else
			break ;
	}
	path = ft_strjoin(temp, "/");
	path = ft_strjoin(path, ((command[i] == '.') ? &command[2] : &command[i]));
	return (path);
}

char		**get_mass(t_command *command, char **env)
{
	char **mass;
	char *temp;
	int i;
	
	mass = (char **)malloc(sizeof(char *) * 1);
	mass[0] = (char *)malloc(sizeof(char) * 1);
	mass[0] = NULL;
	temp = get_path_filename(command->command, env);
	mass = ft_realloc_mass(mass, temp);
	free(temp);
	i = 0;
	if (command->args)
		while (command->args[i])
			mass = ft_realloc_mass(mass, command->args[i++]);
	return (mass);
}

void		run_pid(t_command *command, char **mass)
{
	pid_t pid;
	pid_t wpid;
	int status;
	
	errno = 0;
	pid = fork();
	if (pid == 0)
		execve(mass[0], mass, NULL);
	else if (pid == -1)
		errno_error(command->command, errno);
	else
		wpid = waitpid(pid, &status, WUNTRACED);
	kill(pid, SIGKILL);
}

int			check_stat(t_command *command, char *filename)
{
	int fd;
	int flag;
	struct stat buff;
	
	flag = 0;
	if((fd = open(filename, O_RDONLY)) == (-1))
	{
		g_curr_err = "1";
		errno_error(command->command, errno);
		return (flag);
	}
	fstat(fd, &buff);
	if ((buff.st_mode & S_IRWXG) == (S_IRGRP + S_IWGRP + S_IXGRP) ||
	(buff.st_mode & S_IRWXG) == (S_IWGRP + S_IXGRP) ||
	(buff.st_mode & S_IRWXG) == (S_IRGRP + S_IXGRP) ||
	(buff.st_mode & S_IRWXG) == (S_IXGRP) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR + S_IWUSR) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR + S_IRUSR) ||
	(buff.st_mode & S_IRWXU) == (S_IXUSR + S_IRUSR + S_IWUSR) ||
	(buff.st_mode & S_IRWXO) == (S_IXOTH + S_IROTH + S_IWOTH) ||
	(buff.st_mode & S_IRWXO) == (S_IXOTH + S_IROTH) ||
	(buff.st_mode & S_IRWXO) == (S_IXOTH + S_IWOTH) ||
	(buff.st_mode & S_IRWXO) == (S_IXOTH))
		flag = 1;
	close(fd);
	return (flag);
}

void		file_command(t_command *command, char **env)
{
	char **mass;
	int i;

	mass = get_mass(command, env);
	if (check_stat(command, mass[0]) == 1)
		run_pid(command, mass);
	else
	{
		ft_free_array(mass);
		return ;
	}
	ft_free_array(mass);
	g_curr_err = "0";
}