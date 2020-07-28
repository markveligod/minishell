/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:52:01 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/28 13:52:03 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void do_command(t_command *command)
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
		; // env_command(command);
	else
		external_command(command);
}
