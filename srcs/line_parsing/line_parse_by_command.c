/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse_into_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:05:42 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/31 21:05:46 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Проверяет, корректны ли перенаправления и нет ли после них разделителя
*/

void	error_redirections(char **line, int i, t_ptr *ptr)
{
	if ((ft_strcmp(">>", line[i]) != 0 && ft_strcmp(">", line[i]) != 0
		&& ft_strcmp("<", line[i]) != 0) || (!line[i + 1]
		|| ft_strcmp("|", line[i + 1]) == 0
		|| ft_strcmp(";", line[i + 1]) == 0))
		error("Syntax error", ptr);
}

/*
** _______________________________________________________
** Парсинг входного двумерного массива в структуру команды
** _______________________________________________________
*/

int		line_parse_by_command(char **line, t_ptr *ptr, char **spaces)
{
	int			i;
	int			j;
	t_command	*new;

	if (!(new = init_list_command(new)))
		error("Allocation problem!", ptr);
	free(new->command);
	new->command = NULL;
	i = 0;
	while (line[i])
	{
		if ((ft_strcmp(";", line[i]) == 0 || ft_strcmp("|", line[i]) == 0))
			break;
		if (line[i][0] == '>' || line[i][0] == '<')
		{
			new->flag_v = ft_realloc_mass(new->flag_v, line[i]);
			error_redirections(line, i, ptr);
			new->filename = ft_realloc_mass(new->filename, line[++i]);
			i++;
		}
		else
		{
			line[i] = modify_word(line[i], ptr->is_env);
			if (!(new->command))
				new->command = ft_strdup(line[i]);
			else
			{
				new->spaces = ft_realloc_mass(new->spaces, spaces[i]);
				new->args = ft_realloc_mass(new->args, line[i]);
			}
			i++;
		}
	}
	if (!(new->command))
		new->command = ft_strdup(">");
	ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, new->command);
	ft_lst_add_back(&(ptr->command), new);
	return (i);
}
