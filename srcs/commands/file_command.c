/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:48:27 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/07 13:26:19 by ckakuna          ###   ########.fr       */
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

void		file_command(t_command *command, char **env)
{
	char **mass;
	int i;
	int flag;
	int name_flag;

	name_flag = 0;
	g_curr_err = "0";
	i = ft_strlen(command->command);
	if (command->command[i - 1] == '/')
	{
		if (command->command[i - 2] == '.')
		{
			g_curr_err = "126";
			errno = 13;
			errno_error(command->command, errno);
		}
		else
		{
			g_curr_err = "127";
			errno = 20;
			errno_error(command->command, errno);
		}
		return ;
	}
	mass = get_mass(command, env);
	i = 0;
	flag = check_stat(command, mass[0], name_flag);
	if (flag == 1 && command->filename[i] != NULL)
		while (command->filename[i])
		{
			fork_redirect(command->filename[i], command->flag_v[i], mass);
			i++;
		}
	else if (flag == 1 && command->filename[i] == NULL)
		fork_run(command, mass);
	else
	{
		g_curr_err = "1";
		if (flag == 0)
		{
			errno = 13;
			errno_error(command->command, errno);
		}
		ft_free_array(mass);
		return ;
	}
	ft_free_array(mass);
}