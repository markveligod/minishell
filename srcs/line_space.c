/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:37:23 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/25 16:37:26 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char		*add_one_space(char *line, int *i, char c)
{
	char	*new_line;
	int		j;
	int		now;

	new_line = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 3));
	ft_strlcpy(new_line, line, *i + 1);
	j = *i;
	if (c == 'b')
		new_line[j++] = ' ';
	new_line[j++] = line[*i];
	if (c == 'a')
		new_line[j++] = ' ';
	now = j;
	while (line[(*i = *i + 1)])
		new_line[j++] = line[*i];
	new_line[j] = '\0';
	free(line);
	line = ft_strdup(new_line);
	free(new_line);
	*i = now;
	return (line);
}

char		*add_spaces(char *line, int *i)
{
	char	*new_line;
	int		j;
	int		now;

	new_line = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 3));
	ft_strlcpy(new_line, line, *i + 1);
	j = *i;
	new_line[j++] = ' ';
	new_line[j++] = line[*i];
	if ((line[*i] == '>' && line[*i + 1] == '>') ||
		(line[*i] == '<' && line[*i + 1] == '<'))
	{
		new_line[j++] = line[*i];
		*i = *i + 1;
	}
	new_line[j++] = ' ';
	now = j;
	while (line[(*i = *i + 1)])
		new_line[j++] = line[*i];
	new_line[j] = '\0';
	free(line);
	line = ft_strdup(new_line);
	free(new_line);
	*i = now;
	return (line);
}

int			line_skip_quote(int i, char *line)
{
	if (line[i] == '\"')
	{
		i++;
		while (line[i] && line[i] != '\"')
			i++;
		if (!(line[i]))
			error("QUOTES");
		return (i);
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
		if (!(line[i]))
			error("QUOTES");
		return (i);
	}
	return (i);
}

char		**line_space(char *line)
{
	int		i;
	int		j;
	int		now;

	i = 0;
	while (line[i])
	{
		if ((j = line_skip_quote(i, line)) != i)
		{
			if (i != 0 && line[i - 1] != ' ')
			{
				line = add_one_space(line, &i, 'b');
				j++;
			}
			i = j + 1;
			if (line[i] && line[i] != ' ' && line[--i])
				line = add_one_space(line, &i, 'a');
		}
		else if (line[i] == ';' || line[i] == '|' ||
				line[i] == '>' || line[i] == '<')
			line = add_spaces(line, &i);
		else
			i++;
	}
	return (line_parse(line, ' ', '\t'));
}
