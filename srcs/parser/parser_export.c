/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:37:23 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 14:53:39 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_export	*init_struct_export(t_export *new)
{
	new = (t_export *)malloc(sizeof(t_export));
	new->arg = (char **)malloc(sizeof(char *) * 1);
	new->next = NULL;
	return (new);
}

void		lstadd_back_export(t_export **lst, t_export *new)
{
	t_export	*temp;

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

int			parser_export(char **line, t_ptr *ptr)
{
	int 		i;
	t_export	*new;

	i = 1;
	new = init_struct_export(new);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			new->arg = ft_realloc_mass(new->arg, line[i]);
		else
			break ;
		i++;
	}
	lstadd_back_export(&(ptr->exp), new);
	return (i);
}
