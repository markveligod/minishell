/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:01:31 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 12:00:50 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	clear_malloc(t_ptr *ptr)
{
	t_command		*temp_com;
	
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