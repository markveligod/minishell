/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:47:47 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 08:21:41 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void		export_command(t_ptr *ptr, t_command *t_command)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (t_command->args[i])
	{
		printf("%s\n", t_command->args[i]);
		j = 0;
		while (t_command->args[i][j] && t_command->args[i][j] != '=')
			j++;
		if (t_command->args[i][j] == '\0')
		{
			i++;
			continue ;
		}
		else
		{
			t_command->args[i][j] = '\0';
			temp = ft_strdup(t_command->args[i]);
			ptr->base->is_env = ft_realloc_mass(ptr->base->is_env, temp);
			j++;
			free(temp);
			temp = (t_command->args[i][j] == '\0') ? ft_strdup("") :
			ft_strdup(&t_command->args[i][j]);
			ptr->base->is_env = ft_realloc_mass(ptr->base->is_env, temp);
			free(temp);
		}
		i++;
	}
}