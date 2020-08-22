/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:06:57 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 12:06:58 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void		export_command(t_ptr *ptr, t_command *command)
{
	int		i;

	if (command->args[0] == NULL)
	{
		env_command(ptr->is_env, command);
		i = 0;
		while (ptr->is_export[i] != NULL)
		{
			ft_putstr(ptr->is_export[i]);
			ft_putstr("=' '\n");
			i++;
		}
	}
	else if ((export_equal_args(command->args)) == 1)
	{
		g_curr_err = "1";
		errno_error(command->command, 1);
		return ;
	}
	i = 0;
	while (command->args[i])
		export_com_here(ptr, command, i++);
	g_curr_err = "0";
}
