/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:40:41 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/22 12:45:21 by ckakuna          ###   ########.fr       */
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

void	fail_write_in_file(char *command, errno_t errno_num, char *line)
{
	g_curr_err = "1";
	errno_error(command, errno_num);
	free(line);
	return ;
}

void	write_in_file(t_command *command, char *line)
{
	int flag;
	int i;
	int fd;

	i = -1;
	errno = 0;
	g_curr_err = "0";
	if (command->base == '|')
		ft_putstr_fd(line, 1);
	else
	{
		if (command->flag_v[0] == NULL)
			ft_putstr_fd(line, 1);
		while (command->flag_v[++i])
		{
			flag = create_open_flag(command->flag_v[i]);
			if ((fd = open(command->filename[i], flag, 0666)) == -1)
				return (fail_write_in_file(command->command, errno, line));
			ft_putstr_fd(line, fd);
			if (close(fd) == -1)
				return (fail_write_in_file(command->command, errno, line));
		}
	}
	free(line);
}

int		get_fd(t_command *command)
{
	int flag;
	int fd;

	if (command->flag_v[0] == NULL)
		return (0);
	flag = create_open_flag(command->flag_v[0]);
	if ((fd = open(command->filename[0], flag, 0666)) == -1)
	{
		g_curr_err = "1";
		errno_error(command->command, errno);
		return (-1);
	}
	return (fd);
}
