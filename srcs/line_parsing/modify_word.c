/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:02:35 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/01 18:02:47 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** __________________________________________________________________
** Убирает из слова слеш, заменяет переменные среды и убирает кавычки
** __________________________________________________________________
*/
char	*modify_word(char *word, char **env)
{
	int i;
	char *line;
	char quote;

	i = 0;
	line = ft_strdup(word);
	free(word);
	while (line[i])
	{
		/*
		** Убирает кавычки
		** Если в кавычках есть переменная среды, он ее заменяет
		*/
		quote = line[i];
		if (ft_one_of_them(line[i], "\"\'"))
		{
			line = ft_delete_array_elem(line, i);
			while (line[i])
			{
				if (line[i] == '\\' && line[i + 1] == quote)
				{
					line = ft_delete_array_elem(line, i);
					i++;
				}
				else if (line[i] == '\\' && line[i + 1] == '$' &&
						ft_isalnum(line[i + 2]))
				{
					line = ft_delete_array_elem(line, i);
					i++;
				}
				else if (line[i] == '$' && ft_isalnum(line[i + 1]))
				{
					line = inplace_env(line, env, &i);
					i++;
				}
				else if (line[i] == quote)
				{
					line = ft_delete_array_elem(line, i);
					break ;
				}
				else
					i++;
			}
		}
		/*
		** Убирает \
		*/
		else if (line[i] == '\\' && line[i + 1])
		{
			line = ft_delete_array_elem(line, i);
			i++;
		}
		/*
		** Заменяет переменные среды
		*/
		else if (line[i] == '$' && ft_isalnum(line[i + 1]))
		{
			line = inplace_env(line, env, &i);
			i++;
		}
		else
			i++;
	}
	return (line);
}

