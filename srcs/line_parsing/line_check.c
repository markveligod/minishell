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

char *keep_reading(char *line, char *message)
{
	char *newline;
	char *new;
	int i;
	pid_t pid;
	int status;

	ft_putstr(message);
	ft_putstr(" $> ");
	get_next_line(&newline);
	new = ftstrjoin(line, newline);
	free(newline);
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
	pid_t pid;
	int status;
	int fd[2];
	int in;
	int ret;
	char buffer[11];
	char *stack;

	in = dup(STDIN_FILENO);
	i = 0;
	pipe(fd);
	pid = fork();
	g_signal = 7;
	if (pid == 0)
	{
		newline = ft_strdup(*line);
		while (newline[i])
		{
			if ((j = line_skip_quote(i, newline)) != i)
			{
				i = j + 1;
				if (!(newline[j]))
				{
					signal(SIGINT, exit);
					signal(SIGQUIT, exit);
					tmp = ft_strdup(newline);
					free(newline);
					newline = keep_reading(tmp, "quote");
					free(tmp);
					i = 0;
				}	
			}
			else if (newline[i] == '\\')
			{
				i = i + 2;
				if (!(newline[i - 1]))
				{
					newline = keep_reading(newline, "");
					i = 0;
				}
			}
			else
				i++;
		}
		if (newline[i - 1] == '|')
			newline = keep_reading(newline, "pipe");
		tmp = ft_strdup(newline);
		free(newline);
		newline = ftstrjoin(tmp, "\n");
		free(tmp);
		dup2(fd[1], 1);
		close(fd[0]);
		ft_putstr(newline);
		close(fd[1]);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
		dup2(fd[0], 0);
		close(fd[1]);
		stack = ft_strdup("");
		while ((ret = read(0, buffer, 10)) > 0)
		{
			buffer[ret] = '\0';
			stack = ft_strjoin(stack, buffer);
			if (ft_one_of_them('\n', stack))
				break;
		}
		free(*line);
		*line = ft_substr(stack, 0, ft_strlen(stack) - 1);
		free(stack);
		close(fd[0]);
		dup2(in, STDIN_FILENO);
		close(in);
	}
}