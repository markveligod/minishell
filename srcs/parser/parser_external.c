/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_external_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:45:16 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/27 20:45:18 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_external	*init_struct_external(t_external *external)
{
	if (!(external = (t_external *)malloc(sizeof(t_external))) ||
		!(external->arg = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	external->arg[0] = NULL;
	external->next = NULL;
	return (external);
}

void		lstadd_back_external(t_external **lst, t_external *new)
{
	t_external	*temp;

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

int			parser_external(char **line, t_ptr *ptr)
{
	int			i;
	t_external	*external;

	i = 0;
	if (!(external = init_struct_external(external)))
		error("Allocation problem!", ptr);
	while (line[i] != NULL)
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			external->arg = ft_realloc_mass(external->arg, line[i]);
		else
			break;
		i++;
	}
	lstadd_back_external(&(ptr->external), external);
	return (i);
}
