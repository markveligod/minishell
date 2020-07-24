/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:50:46 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 17:29:34 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

t_echo	*init_list_echo(t_echo *new)
{
	new = (t_echo *)malloc(sizeof(t_echo));
	new->fd = (char **)malloc(sizeof(char *) * 1);
	new->flag_v = (char **)malloc(sizeof(char *) * 1);
	new->fd[0] = NULL;
	new->flag_v[0] = NULL;
	new->flag_n = 0;
	new->next = NULL;
	return (new);
}

int		check_nnn(char **str, t_echo *new)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp("-n", str[i]) != 0)
			break;
		else
		{
			new->flag_n = 1;
			i++;
		}
	}
	return (i);
}

void	lstadd_back_echo(t_echo **lst, t_echo *new)
{
	t_echo	*temp;

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

int 	parser_echo(char **line, t_ptr *ptr)
{
	int i;
	t_echo *new;

	i = 1;
	new = init_list_echo(new);
	i += check_nnn(&line[i], new);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) == 0)
		{
			break ;
		}
		if (ft_strcmp("|", line[i]) == 0)
		{
			break ;
		}
		if (ft_strcmp(">>", line[i]) == 0 || ft_strcmp(">", line[i]) == 0 || ft_strcmp("<", line[i]) == 0)
		{
			create_flag_v(new, line[i]);
			if (!line[i + 1] || ft_strcmp("|", line[i + 1]) == 0 || ft_strcmp(";", line[i + 1]) == 0)
				error("Syntex error");
			else
				create_file_v(new, line[++i]);
			i++;
			continue ;
		}
		new->line = ft_strjoin(new->line, line[i]);
	}
	lstadd_back_echo(&(ptr->ec), new);
	return (i);
}
