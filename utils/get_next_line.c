/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:55:15 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/03 09:06:41 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*push_line(char *remains)
{
	int i;
	char *array;

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
	int i;
	int j;
	char *array;

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

int		check_eof(char c)
{
	if (c == 0)
	{
		ft_putstr("logout\n");
		exit(1);
	}
	return (0);
}

int		get_next_line(char **line)
{
	char		*buffer;
	static char	*remains;
	int			count;
	int			flag;

	count = 1;
	flag = 1;
	if (!line)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (buffer[0] != '\n' && count != 0)
	{
		if ((count = read(0, buffer, BUFFER_SIZE)) == (-1))
			return (-1);
		if (flag == 1)
			flag = check_eof(buffer[0]);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	free(buffer);
	*line = push_line(remains);
	remains = cut_next_line(remains);
	return((count == 0) ? 0 : 1);
}
