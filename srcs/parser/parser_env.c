/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:47:38 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 16:04:26 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

t_env	*init_struct_env(t_env *new)
{
	if (!(new = (t_env *)malloc(sizeof(t_env))) ||
		!(new->arg = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	new->arg[0] = NULL;
	new->next = NULL;
	return (new);
}

void		lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*temp;

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

int			parser_env(char **line, t_ptr *ptr)
{
	int 		i;
	t_env		*new;

	i = 1;
	if (!(new = init_struct_env(new)))
		error("Allocation problem!", ptr);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) != 0 && ft_strcmp("|", line[i]) != 0)
			new->arg = ft_realloc_mass(new->arg, line[i]);
		else
			break ;
		i++;
	}
	lstadd_back_env(&(ptr->env), new);
	return (i);
}
