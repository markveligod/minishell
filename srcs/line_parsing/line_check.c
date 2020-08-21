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

int			line_skip_quote(int i, char *line)
{
	char	quote;

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
**  Проверяет строку на закрытие кавычек или \
** ____________________________________________
**   - Если в строке есть незакрытая кавычка или
**     пустой слэш, то читаем дальше
**
**         line_check - основная функция
** - Создаем процесс-ребенок, в нем проходимся
**   по строке (through_line), если встречаем
**   незакрытую кавычку, читаем дальше (if_not_closed),
**   передаем дописанную строку родителю
** - В родителе принимаем новую строку (read_new_line)
*/

void		if_not_closed(int *i, char **newline, char *message, char symb)
{
	char *line;
	char *new;

	if (!(symb))
	{
		signal(SIGINT, exit);
		signal(SIGQUIT, exit);
		ft_putstr(message);
		ft_putstr(" $> ");
		get_next_line(&line);
		new = ft_strdup(*newline);
		free(*newline);
		*newline = ft_strjoin(new, line);
		free(line);
		*i = -1;
	}
}

char		*through_line(char *line)
{
	int		i;
	int		j;
	char	*newline;

	i = -1;
	newline = ft_strdup(line);
	while (newline[++i])
	{
		if ((j = line_skip_quote(i, newline)) != i)
		{
			i = j + 1;
			if_not_closed(&i, &newline, "quote", newline[j]);
		}
		else if (newline[i] == '\\' && !(newline[i + 1]))
			if_not_closed(&i, &newline, "", '\0');
		else if (newline[i] == '\\')
			i = i + 2;
		else if (newline[i] == '|')
		{
			while (newline[++i] == ' ' || newline[i] == '\t')
				i++;
			if_not_closed(&i, &newline, "pipe", newline[i]);
		}
	}
	return (newline);
}

void		read_new_line(char **line, int *fd, int in)
{
	char	*stack;
	int		ret;
	char	buffer[11];

	dup2(fd[0], 0);
	close(fd[1]);
	free(*line);
	if (g_signal != 8)
	{
		stack = ft_strdup("");
		while ((ret = read(0, buffer, 10)) > 0)
		{
			buffer[ret] = '\0';
			stack = ft_strjoin(stack, buffer);
			if (ft_one_of_them('\n', stack))
				break ;
		}
		*line = ft_substr(stack, 0, ft_strlen(stack) - 1);
		free(stack);
	}
	close(fd[0]);
	dup2(in, STDIN_FILENO);
	close(in);
}

void		line_check(char **line)
{
	char	*newline;
	pid_t	pid;
	int		status;
	int		fd[2];
	int		in;

	in = dup(STDIN_FILENO);
	pipe(fd);
	pid = fork();
	g_signal = 7;
	if (pid == 0)
	{
		newline = through_line(*line);
		newline = ft_strjoin(newline, "\n");
		dup2(fd[1], 1);
		close(fd[0]);
		ft_putstr(newline);
		close(fd[1]);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
		read_new_line(line, fd, in);
	}
}
