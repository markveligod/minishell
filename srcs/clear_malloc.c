/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:26:13 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/19 16:26:16 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	clear_malloc(t_ptr *ptr)
{
	t_command		*temp_com;

	g_flag = 0;
	if (ptr->command != NULL)
		while (ptr->command)
		{
			temp_com = ptr->command->next;
			ft_free_array(ptr->command->filename);
			ft_free_array(ptr->command->flag_v);
			ft_free_array(ptr->command->args);
			ft_free_array(ptr->command->spaces);
			free(ptr->command->command);
			free(ptr->command);
			ptr->command = temp_com;
		}
	if (ptr->base != NULL)
	{
		ft_free_array(ptr->base->flag_base);
		ft_free_array(ptr->base->ar_base);
		free(ptr->base);
	}
}
