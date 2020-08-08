/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:25:35 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/03 10:23:06 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	cd_command(t_command *command, char **env)
{
	errno_t		error_num;
	int			len;
	int			i;
	char		*path;
	char		*cwd;

	errno = 0;
	g_curr_err = "0";
	len = ft_mass_len(command->args);
	if (len > 1)
	{
		g_curr_err = "1";
		ft_putstr_fd("cd: Too many arguments\n", 0);
		return ;
	}
	if (len == 0)
	{
		i = 0;
		while (ft_strcmp(env[i], "HOME") != 0)
			i++;
		path = ft_strdup(env[++i]);
	}
	else
		path = ft_strdup(command->args[0]);
	if (chdir(path) != 0)
	{
		g_curr_err = "1";
		errno_error(command->command, errno);
	}
	else
	{
		i = 0;
		while (ft_strcmp(env[i], "PWD") != 0)
			i++;
		free(path);
		path = ft_strdup(env[++i]);
		free(env[i]);
		env[i] = NULL;
		cwd = getcwd(NULL, 10);
		env[i] = ft_strdup(cwd);
		free(cwd);
		i = 0;
		while (ft_strcmp(env[i], "OLDPWD") != 0)
			i++;
		free(env[++i]);
		env[i] = NULL;
		env[i] = ft_strdup(path);
	}
	free(path);
	write_in_file(command, ft_strdup(""));
}
