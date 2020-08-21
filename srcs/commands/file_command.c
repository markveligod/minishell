/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:48:27 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/21 16:25:59 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

char		*new_str(char *path, char *curr_pwd, int i)
{
	char *new_path;

	new_path = ft_strdup(curr_pwd);
	free(curr_pwd);
	new_path = ft_strjoin(new_path, "/");
	new_path = ft_strjoin(new_path, &path[i]);
	return (new_path);
}

char		*dot_dot_path(char *path, char *curr_pwd)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(curr_pwd) - 1;
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/')
		{
			while (curr_pwd[j] != '/')
				j--;
			curr_pwd[j] = '\0';
			j--;
			i += 3;
			continue ;
		}
		else if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] != '/')
			return (NULL);
		else
			break ;
	}
	return (new_str(path, curr_pwd, i));
}

char		*join_path(char *path, char *curr_pwd, int flag)
{
	char *new_path;

	new_path = ft_strdup(curr_pwd);
	free(curr_pwd);
	if (flag == 1)
		new_path = ft_strjoin(new_path, &path[1]);
	else
	{
		new_path = ft_strjoin(new_path, "/");
		new_path = ft_strjoin(new_path, path);
	}
	free(path);
	return (new_path);
}

char		*relative_path(char *path)
{
	char *curr_pwd;

	if (!(curr_pwd = getcwd(NULL, 10)))
		return (NULL);
	if (path[0] == '.' && path[1] == '.')
		return (dot_dot_path(path, curr_pwd));
	else if (path[0] == '.' && path[1] == '/')
		return (join_path(path, curr_pwd, 1));
	else
		return (join_path(path, curr_pwd, 0));
	return (NULL);
}

int			check_stat(t_command *command, char *filename, int name_flag)
{
	int			fd;
	int			flag;
	struct stat	buff;

	flag = 0;
	if ((fd = open(filename, O_RDONLY)) == (-1))
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
