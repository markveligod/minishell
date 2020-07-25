/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_space_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 22:58:54 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/25 22:58:55 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int		if_space(int *len, int i, char **spaces, char *line)
{
	int		s;
	int		j;

	s = 0;
	j = i;
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
		s++;
	}
	if (!(spaces[*len] = (char *)malloc(sizeof(char) * (s + 1))))
		error("Allocation problem");
	s = 0;
	i = j;
	while (line[i] == ' ' || line[i] == '\t')
	{
		spaces[*len][s] = line[i];
		s++;
		i++;
	}
	spaces[*len][s] = '\0';
	*len = *len + 1;
	return (i);
}

char	**line_space_counter(char *line, int len)
{
	char	**spaces;
	int		i;
	int		j;

	if (!(spaces = (char **)malloc(sizeof(char *) * (len + 1))))
		error("Allocation problem");
	spaces[len] = NULL;
	len = 0;
	i = 0;
	while (line[i])
	{
		if (i == 0 && (line[i] == ' ' || line[i] == '\t'))
			while (line[i] == ' ' || line[i] == '\t')
				i++;
		if ((j = line_skip_quote(i, line)) != i)
			i = j + 1;
		else if (line[i] == ';' || line[i] == '|' ||
				 line[i] == '>' || line[i] == '<')
		{
			i++;
			if (line[i - 1] == '>' && line[i] == '>')
				i++;
		}
		else
			while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != ';' &&
				   line[i] != '|' && line[i] != '>' && line[i] != '<' &&
				   line[i] != '\"' && line[i] != '\'')
				i++;
		i = if_space(&len, i, spaces, line);
	}
	free(line);
	return (spaces);
}
