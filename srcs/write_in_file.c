/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:35:02 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/28 15:35:04 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** Создает флаги режимов для открытия файла
*/

int		create_open_flag(char *flag)
{
	int open;

	if (ft_strcmp(flag, ">>") == 0)
		open = O_RDWR | O_CREAT | O_APPEND;
	else if (ft_strcmp(flag, ">") == 0)
		open = O_RDWR | O_CREAT | O_TRUNC;
	else
		open = O_RDONLY;
	return (open);
}

/*
** Вывод содержимого функций в файл или на печать
*/

void	write_in_file(t_command *command, char *line)
{
	int 		flag;
	int 		i;
	int			fd;
	errno_t		error_num;

	i = 0;
	errno = 0;
	if (command->flag_v[0] == NULL)
		ft_putstr_fd(line, 1);
	while (command->flag_v[i])
	{
		flag = create_open_flag(command->flag_v[i]);
		if ((fd = open(command->filename[i], flag, 0666)) == -1)
		{
			error_num = errno;
			printf("echo: %s\n", (char *)strerror(error_num));
			return ;
		}
		ft_putstr_fd(line, fd);
		if (close(fd) == -1)
		{
			error_num = errno;
			printf("echo: %s\n", (char *)strerror(error_num));
			return ;
		}
		i++;
	}
}
