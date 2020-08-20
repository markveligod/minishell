/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:35:12 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/03 18:35:19 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** ____________________________________________
**        Пропускает всё, что в кавычках
** ____________________________________________
**   - Если символ, поданый на вход - кавычка,
**     вернет индекс закрывающей кавычки;
*/

int line_skip_quote(int i, char *line)
{
	char quote;

	quote = line[i];
	if (ft_one_of_them(line[i], "\"\'"))
	{
		i++;
		while (line[i])
		{
			if (line[i] == '\\' && line[i + 1] == quote)
				i = i + 2;
			else if (line[i] == quote)
				return (i);
			else
				i++;
		}
	}
	return (i);
}

/*
** ____________________________________________
**              Считывает строку
** ____________________________________________
*/

char		*keep_reading(char *line, char *message)
{
	char	*newline;
	char	*new;
	int		i;
	pid_t	pid;
	int		status;

	g_signal = 4;
	ft_putstr(message);
	ft_putstr(" $> ");
	pid = fork();
	if (pid < 0)
		return (NULL);
	if (pid == 0)
	{
		signal(SIGINT, exit);
		signal(SIGQUIT, exit);
		get_next_line(&newline);
		new = ft_strjoin(line, newline);
		free(newline);
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return (new);
}

/*
** ____________________________________________
**  Проверяет строку на закрытие кавычек или \
** ____________________________________________
**   - Если в строке есть незакрытая кавычка или
**     пустой слэш, то читаем дальше
*/

void		line_check(char **line)
{
	int i;
	int j;
	char quote;
	char *newline;
	char *tmp;

	i = 0;
	newline = ft_strdup(*line);
	while (newline[i])
	{
		if ((j = line_skip_quote(i, newline)) != i)
		{
			i = j + 1;
			if (!(newline[j]))
			{
				tmp = ft_strdup(newline);
				free(newline);
				newline = keep_reading(tmp, "quote");
				if (g_signal == 3)
					return;
				i = 0;
			}	
		}
		else if (newline[i] == '\\')
		{
			i = i + 2;
			if (!(newline[i - 1]))
			{
				tmp = ft_strdup(newline);
				free(newline);
				newline = keep_reading(tmp, "");
				i = 0;
			}
		}
		else
			i++;
	}
	if (newline[i - 1] == '|')
	{
		tmp = ft_strdup(newline);
		free(newline);
		newline = keep_reading(tmp, "pipe");
	}
	free(*line);
	*line = ft_strdup(newline);
	free(newline);
}