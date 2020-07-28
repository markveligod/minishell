/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:50:46 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/27 09:34:11 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** Добавление элемента в конец списка
*/

void	lstadd_back_command(t_command **lst, t_command *new)
{
	t_command	*temp;

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

/*
** Проверяет, корректны ли перенаправления и нет ли после них разделителя
*/

void	if_error(char **line, int i, t_ptr *ptr)
{
	if ((ft_strcmp(">>", line[i]) != 0 && ft_strcmp(">", line[i]) != 0
		&& ft_strcmp("<", line[i]) != 0) || (!line[i + 1]
		|| ft_strcmp("|", line[i + 1]) == 0
		|| ft_strcmp(";", line[i + 1]) == 0))
		error("Syntax error", ptr);
}

/*
** Парсинг входного двумерного массива в структуру команды
*/

int		parser_command(char **line, t_ptr *ptr, char **spaces)
{
	int			i;
	t_command	*new;

	i = 1;
	if (!(new = init_list_command(new)))
		error("Allocation problem!", ptr);
	new->command = ft_strdup(line[0]);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) == 0 || ft_strcmp("|", line[i]) == 0)
			break ;
		if (line[i][0] == '>' || line[i][0] == '<')
		{
			new->flag_v = ft_realloc_mass(new->flag_v, line[i]);
			if_error(line, i, ptr);
			new->filename = ft_realloc_mass(new->filename, line[++i]);
			i++;
			continue ;
		}
		new->spaces = ft_realloc_mass(new->spaces, spaces[i]);
		new->args = ft_realloc_mass(new->args, line[i]);
		i++;
	}
	lstadd_back_command(&(ptr->command), new);
	return (i);
}
