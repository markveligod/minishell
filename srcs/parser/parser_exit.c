/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:49:48 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 16:04:36 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_exit	*init_struct_exit(t_exit *new)
{
	new = (t_exit *)malloc(sizeof(t_exit));
	new->arg = (char **)malloc(sizeof(char *) * 1);
	new->arg = NULL;
	new->next = NULL;
	return (new);
}

void		lstadd_back_exit(t_exit **lst, t_exit *new)
{
	t_exit	*temp;

	if (!(*lst))
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int			parser_exit(char **line, t_ptr *ptr)
{
	int 		i;
	t_exit	*new;

	i = 1;
	new = init_struct_exit(new);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			new->arg = ft_realloc_mass(new->arg, line[i]);
		else
			break ;
		i++;
	}
	lstadd_back_exit(&(ptr->exit), new);
	return (i);
}
