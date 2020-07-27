/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 09:56:38 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 16:03:59 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_cd	*init_struct_cd(t_cd *new)
{
	if (!(new = (t_cd *)malloc(sizeof(t_cd))) ||
		!(new->path = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	new->path[0] = NULL;
	new->next = NULL;
	return (new);
}

void	lstadd_back_cd(t_cd **lst, t_cd *new)
{
	t_cd	*temp;

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

int		parser_cd(char **line, t_ptr *ptr)
{
	int i;
	t_cd *new;

	i = 1;
	if (!(new = init_struct_cd(new)))
		error("Allocation problem!", ptr);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			new->path = ft_realloc_mass(new->path, line[i]);
		else
			break ;
		i++;
	}
	lstadd_back_cd(&(ptr->cd), new);
	return (i);
}
