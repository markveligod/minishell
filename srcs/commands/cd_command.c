/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:25:35 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/19 15:19:49 by ckakuna          ###   ########.fr       */
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

void	cd_command(t_command *command, t_ptr *ptr)
{
	errno_t		error_num;
	int			len;
	int			i;
	char		*path;
	char		*cwd;

	errno = 0;
	len = ft_mass_len(command->args);
	cwd = getcwd(NULL, 10);
	if (len > 1)
	{
		g_curr_err = "1";
		ft_putstr_fd("cd: Too many arguments\n", 0);
		return ;
	}
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
	{
		g_curr_err = "1";
		errno_error(command->command, errno);
		free(path);
		free(cwd);
		return ;
	}
	else
		change_pwd(&cwd, ptr);
	free(cwd);
	free(path);
	write_in_file(command, ft_strdup(""));
	g_curr_err = "0";
}
