/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:35:02 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/03 09:38:25 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** Создает флаги режимов для открытия файла
*/

int			create_open_flag(char *flag)
{
	int		open;

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

void		write_in_file(t_command *command, char *line)
{
	int		flag;
	int		i;
	int		fd;
	errno_t	error_num;

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
			{
				g_curr_err = "1";
				errno_error(command->command, errno);
				free(line);
				return;
			}
			ft_putstr_fd(line, fd);
			if (close(fd) == -1)
			{
				g_curr_err = "1";
				errno_error(command->command, errno);
				free(line);
				return;
			}
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
		return(-1);
	}
	return(fd);
}
