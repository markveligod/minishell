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

void	cd_command(t_command *command)
{
	errno_t		error_num;
	int			len;
	char		*infile;

	errno = 0;
	len = ft_mass_len(command->args);
	infile = ft_strdup("");
	if (len != 1 && len != 0)
	{
		ft_putstr_fd("cd: Too many arguments\n", 0);
		return ;
	}
	if (len == 0)
		command->args[0] = ft_strdup("/");
	if (chdir(command->args[0]) != 0)
		errno_error(command->command, errno);
	write_in_file(command, infile);
}
