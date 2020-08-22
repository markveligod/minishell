/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:55:15 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/19 14:25:09 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*push_line(char *remains)
{
	int		i;
	char	*array;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*cut_next_line(char *remains)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	i++;
	while (remains[i])
	{
		array[j] = remains[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free(remains);
	return (array);
}

/*
** Функция для обработки ctrl + D
*/

int		get_next_line(char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remains;
	int			count;

	count = 1;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && count != 0)
	{
		count = read(0, buffer, BUFFER_SIZE);
		if (g_signal == 1)
			return (0);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
		if (count == 0 && remains[0] == 0 && g_signal != 7)
		{
			ft_putstr("logout\n");
			exit(1);
		}
		else
			count = 1;
	}
	*line = push_line(remains);
	remains = cut_next_line(remains);
	return ((count == 0) ? 0 : 1);
}
