/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:35:12 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 11:35:14 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** __________________________________________________________________
** Убирает из слова слеш, заменяет переменные среды и убирает кавычки
** __________________________________________________________________
*/

/*
** Убирает кавычки
** Если в кавычках есть переменная среды, он ее заменяет
*/

char	*delete_quotes(char *oldline, int *i, char **env, char quote)
{
	char	*line;
	int		j;

	j = *i;
	line = ft_strdup(oldline);
	free(oldline);
	line = ft_delete_array_elem(line, *i);
	while (line[j])
	{
		if (line[j] == '\\' && (line[j + 1] == quote ||
				(line[j + 1] == '$' && ft_isalnum(line[j + 2]))))
			line = ft_delete_array_elem(line, j++);
		else if (line[j] == '$' && (ft_isalnum(line[j + 1]) ||
									line[j + 1] == '?'))
			line = inplace_env(line, env, &j);
		else if (line[j] == quote)
		{
			line = ft_delete_array_elem(line, j);
			break ;
		}
		else
			j++;
	}
	*i = j;
	return (line);
}

char	*modify_word(char *word, char **env)
{
	int		i;
	char	*line;
	char	quote;

	i = 0;
	line = ft_strdup(word);
	free(word);
	while (line[i])
	{
		quote = line[i];
		if (ft_one_of_them(line[i], "\"\'"))
			line = delete_quotes(line, &i, env, quote);
		else if (line[i] == '\\' && line[i + 1])
		{
			line = ft_delete_array_elem(line, i);
			i++;
		}
		else if (line[i] == '$' && (ft_isalnum(line[i + 1]) ||
									line[i + 1] == '?'))
			line = inplace_env(line, env, &i);
		else
			i++;
	}
	return (line);
}
