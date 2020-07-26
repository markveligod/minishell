/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:21:35 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 14:53:43 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_pwd	*init_struct_pwd(t_pwd *new)
{
	new = (t_pwd *)malloc(sizeof(t_pwd));
	new->arg = (char **)malloc(sizeof(char *) * 1);
	new->next = NULL;
	return (new);
}

void	lstadd_back_pwd(t_pwd **lst, t_pwd *new)
{
	t_pwd	*temp;

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

int		parser_pwd(char **line, t_ptr *ptr)
{
	int i;
	t_pwd *new;

	i = 1;
	new = init_struct_pwd(new);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			new->arg = ft_realloc_mass(new->arg, line[i]);
		else
			break ;
		i++;
	}
	lstadd_back_pwd(&(ptr->pwd), new);
	return (i);
}
