/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 09:56:38 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 10:24:04 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

t_cd	*init_struct_cd(t_cd *new)
{
	new = (t_cd *)malloc(sizeof(t_cd));
	new->path = ft_strdup("");
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
	new = init_struct_cd(new);
	if (ft_strcmp(";", line[i]) != 0 || ft_strcmp("|", line[i]) != 0)
		new->path = ft_strjoin(new->path, line[i]);
	lstadd_back_cd(&(ptr->cd), new);
	return (i);
}