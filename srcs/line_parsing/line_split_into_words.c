/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_split_into_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:42:40 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/31 19:42:42 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** ____________________________________________
**           Создает массив пробелов
** ____________________________________________
*/
void		line_count_spaces(char *line, char ***spaces)
{
	int		i;
	char	*word;

	i = 0;
	while (ft_one_of_them(line[i], " \t"))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	word[i] = '\0';
	i = 0;
	while (ft_one_of_them(line[i], " \t"))
	{
		word[i] = line[i];
		i++;
	}
	*spaces = ft_realloc_mass(*spaces, word);
	free(word);
}

/*
** ______________________________________________
** Подсчитывает и возвращает длину слова в строке
** ______________________________________________
*/

int			count_word_len(char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i])
	{
		if ((j = line_skip_quote(i, line)) != i)
			i = j + 1;
		else if (line[i] == '\\')
			i = (line[i + 1] ? i + 2 : i + 1);
		else if (i == 0 && ft_one_of_them(line[i], ";|><"))
		{
			i++;
			if (ft_one_of_them(line[i - 1], "><"))
				while (ft_one_of_them(line[i], "><"))
					i++;
			return (i);
		}
		else if (ft_one_of_them(line[i], " \t;|><"))
			return (i);
		else
			i++;
	}
	return (i);
}

/*
** ____________________________________________
**    Разбивает строку на слова и возвращает
**           двумерный массив слов
** ____________________________________________
*/

char		**line_split_into_words(char *line, char ***spaces)
{
	char	**mass;
	char	*word;
	int		i;
	int		symb;
	int		len;

	i = 0;
	mass = (char **)malloc(sizeof(char *));
	*spaces = (char **)malloc(sizeof(char *));
	mass[0] = NULL;
	*spaces[0] = NULL;
	while (ft_one_of_them(line[i], " \t"))
		i++;
	while (line[i])
	{
		len = count_word_len(&line[i]);
		word = (char *)malloc(sizeof(char) * (len + 1));
		word[len] = '\0';
		symb = 0;
		while (symb != len)
			word[symb++] = line[i++];
		mass = ft_realloc_mass(mass, word);
		free(word);
		line_count_spaces(&line[i], spaces);
		while (ft_one_of_them(line[i], " \t"))
			i++;
	}
	free(line);
	return (mass);
}
