/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:48:29 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 06:48:18 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	error(char *str, t_ptr *ptr)
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