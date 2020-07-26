/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:43:32 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 14:53:47 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_unset	*init_struct_unset(t_unset *new)
{
	new = (t_unset *)malloc(sizeof(t_unset));
	new->arg = (char **)malloc(sizeof(char *) * 1);
	new->next = NULL;
	return (new);
}

void		lstadd_back_unset(t_unset **lst, t_unset *new)
{
	t_unset	*temp;

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

int			parser_unset(char **line, t_ptr *ptr)
{
	int 		i;
	t_unset	*new;

	i = 1;
	new = init_struct_unset(new);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			new->arg = ft_realloc_mass(new->arg, line[i]);
		else
			break ;
		i++;
	}
	lstadd_back_unset(&(ptr->un), new);
	return (i);
}
