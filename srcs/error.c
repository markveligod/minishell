/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:29:37 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/19 16:29:39 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void		error(char *str, t_ptr *ptr)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	ft_putstr("\n");
	clear_malloc(ptr);
	read_input(ptr);
}

/*
** Сообщение об ошибке от errno
*/

void		errno_error(char *com_name, errno_t error_num)
{
	char	*message;

	message = ftstrjoin(com_name, ": ");
	if (error_num == -5)
		message = ft_strjoin(message, "command not found");
	else
		message = ft_strjoin(message, (char *)strerror(error_num));
	message = ft_strjoin(message, "\n");
	ft_putstr_fd(message, 0);
	free(message);
}
