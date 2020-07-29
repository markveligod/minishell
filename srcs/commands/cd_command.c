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

#include "../../minish.h"

void	cd_command(t_command *command, char **env)
{
	errno_t		error_num;
	int			len;
	char		*infile;
	int			i;
	char		*path;

	errno = 0;
	len = ft_mass_len(command->args);
	infile = ft_strdup("");
	if (len != 1 && len != 0)
	{
		ft_putstr_fd("cd: Too many arguments\n", 0);
		return ;
	}
	if (len == 0)
	{
		i = 0;
		while (ft_strcmp(env[i], "HOME") != 0)
			i++;
		command->args[0] = ft_strdup(env[++i]);
	}
	if (chdir(command->args[0]) != 0)
		errno_error(command->command, errno);
	else
	{
		i = 0;
		while (ft_strcmp(env[i], "PWD") != 0)
			i++;
		path = ft_strdup(env[++i]);
		free(env[i]);
		env[i] = NULL;
		env[i] = ft_strdup(getcwd(NULL, 10));
		i = 0;
		while (ft_strcmp(env[i], "OLDPWD") != 0)
			i++;
		free(env[++i]);
		env[i] = NULL;
		env[i] = ft_strdup(path);
		free(path);
	}
	write_in_file(command, infile);
}
