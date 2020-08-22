/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:25:35 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 13:09:16 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	change_pwd(char **cwd, t_ptr *ptr)
{
	int i;

	i = 0;
	while (ptr->is_env[i] && ft_strcmp(ptr->is_env[i], "OLDPWD") != 0)
		i++;
	if (!(ptr->is_env[i]))
	{
		ptr->is_env = ft_realloc_mass(ptr->is_env, "OLDPWD");
		ptr->is_env = ft_realloc_mass(ptr->is_env, "");
	}
	free(ptr->is_env[++i]);
	ptr->is_env[i] = ft_strdup(*cwd);
	free(*cwd);
	*cwd = getcwd(NULL, 10);
	i = 0;
	while (ptr->is_env[i] && ft_strcmp(ptr->is_env[i], "PWD") != 0)
		i++;
	if (!(ptr->is_env[i]))
	{
		ptr->is_env = ft_realloc_mass(ptr->is_env, "PWD");
		ptr->is_env = ft_realloc_mass(ptr->is_env, "");
	}
	free(ptr->is_env[++i]);
	ptr->is_env[i] = ft_strdup(*cwd);
}

int		fail_cd(t_command *command, errno_t error_num, char **cwd, char **path)
{
	g_curr_err = "1";
	free(*cwd);
	if (error_num == 0)
		ft_putstr_fd("cd: Too many arguments\n", 0);
	else
	{
		free(*path);
		errno_error(command->command, error_num);
	}
	return (1);
}

int		reset_cd(char *cwd, char *path, t_command *command)
{
	free(cwd);
	free(path);
	write_in_file(command, ft_strdup(""));
	g_curr_err = "0";
	return (0);
}

int		cd_command(t_command *command, t_ptr *ptr)
{
	int			len;
	int			i;
	char		*path;
	char		*cwd;

	errno = 0;
	len = ft_mass_len(command->args);
	cwd = getcwd(NULL, 10);
	path = NULL;
	if (len > 1)
		return (fail_cd(command, errno, &cwd, &path));
	if (len == 0)
	{
		i = 0;
		while (ptr->is_env[i] && ft_strcmp(ptr->is_env[i], "HOME") != 0)
			i++;
		path = ptr->is_env[i] ? ft_strdup(ptr->is_env[++i]) : ft_strdup(cwd);
	}
	else
		path = ft_strdup(command->args[0]);
	if (chdir(path) != 0)
		return (fail_cd(command, errno, &cwd, &path));
	else
		change_pwd(&cwd, ptr);
	return (reset_cd(cwd, path, command));
}
