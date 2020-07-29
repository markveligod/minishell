/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:52:01 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/29 07:26:46 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	do_command(t_command *command, t_ptr *ptr)
{
	if (ft_strcmp(command->command, "echo") == 0)
		echo_command(command);
	else if (ft_strcmp(command->command, "cd") == 0)
		cd_command(command);
	else if (ft_strcmp(command->command, "pwd") == 0)
		pwd_command(command);
	else if (ft_strcmp(command->command, "exit") == 0)
		; //exit_command(command);
	else if (ft_strcmp(command->command, "export") == 0)
		; //export_command(command);
	else if (ft_strcmp(command->command, "unset") == 0)
		; //unset_command(command);
	else if (ft_strcmp(command->command, "env") == 0)
		env_command(ptr->base->is_env);
	else
		external_command(command);
}
