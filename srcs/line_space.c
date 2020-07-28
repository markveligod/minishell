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

char		*add_one_space(char *line, int *i, char c, t_ptr *ptr)
{
	char	*new_line;
	int		j;
	int		now;

	if (!(new_line = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 3))))
		error("Allocation problem", ptr);
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

char		*add_spaces(char *line, int *i, t_ptr *ptr)
{
	char	*new_line;
	int		j;
	int		now;

	if (!(new_line = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 3))))
		error("Allocation problem", ptr);
	ft_strlcpy(new_line, line, *i + 1);
	j = *i;
	new_line[j++] = ' ';
	new_line[j++] = line[*i];
	while (line[*i + 1] == '>' || line[*i + 1] == '<')
	{
		new_line[j++] = line[*i];
		*i = *i + 1;
	}
	/*if ((line[*i] == '>' && line[*i + 1] == '>') ||
		(line[*i] == '<' && line[*i + 1] == '<'))
	{
		new_line[j++] = line[*i];
		*i = *i + 1;
	}*/
	new_line[j++] = ' ';
	now = j;
	while (line[(*i = *i + 1)])
		new_line[j++] = line[*i];
	new_line[j] = '\0';
	free(line);
	if (!(line = ft_strdup(new_line)))
		error("Allocation problem", ptr);
	free(new_line);
	*i = now;
	return (line);
}

int		line_skip_quote(int i, char *line, t_ptr *ptr)
{
	if (line[i] == '\"')
	{
		i++;
		while (line[i] && line[i] != '\"')
			i++;
		if (!(line[i]))
			error("QUOTES", ptr);
		return (i);
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
		if (!(line[i]))
			error("QUOTES", ptr);
		return (i);
	}
	return (i);
}

char		**line_space(char *line, t_ptr *ptr)
{
	int		i;
	int		j;
	int		now;
	char	**args;

	i = 0;
	while (line[i])
	{
		if ((j = line_skip_quote(i, line, ptr)) != i)
		{
			if (i != 0 && line[i - 1] != ' ')
			{
				line = add_one_space(line, &i, 'b', ptr);
				j++;
			}
			i = j + 1;
			if (line[i] && line[i] != ' ' && line[--i])
				line = add_one_space(line, &i, 'a', ptr);
		}
		else if (line[i] == ';' || line[i] == '|' ||
				line[i] == '>' || line[i] == '<')
			line = add_spaces(line, &i, ptr);
		else
			i++;
	}
	if ((args = line_parse(line, ' ', '\t')) == NULL)
		error("Allocation problem!", ptr);
	return (args);
}
