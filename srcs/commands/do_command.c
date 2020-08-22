/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:52:01 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 13:11:32 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	do_command(t_command *command, t_ptr *ptr)
{
	if (ft_strcmp(command->command, "echo") == 0)
		echo_command(command);
	else if (ft_strcmp(command->command, "cd") == 0)
		cd_command(command, ptr);
	else if (ft_strcmp(command->command, "pwd") == 0)
		pwd_command(command);
	else if (ft_strcmp(command->command, "exit") == 0)
		exit_command(ptr);
	else if (ft_strcmp(command->command, "export") == 0)
		export_command(ptr, command);
	else if (ft_strcmp(command->command, "unset") == 0)
		unset_command(ptr, command);
	else if (ft_strcmp(command->command, "env") == 0)
		env_command(ptr->is_env, command);
	else if (ft_strcmp(command->command, "$?") == 0)
		curr_err_command(1);
	else if (ft_strcmp(command->command, ">") == 0)
		redirect_command(command);
	else
		external_command(command, ptr->is_env);
}

int		if_internal_command(t_command *command)
{
	return (ft_strcmp(command->command, "echo") == 0 ||
		ft_strcmp(command->command, "cd") == 0 ||
		ft_strcmp(command->command, "pwd") == 0 ||
		ft_strcmp(command->command, "exit") == 0 ||
		ft_strcmp(command->command, "export") == 0 ||
		ft_strcmp(command->command, "unset") == 0 ||
		ft_strcmp(command->command, "env") == 0 ||
		ft_strcmp(command->command, "$?") == 0 ||
		ft_strcmp(command->command, ">") == 0);
}
