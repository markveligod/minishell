/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:39:31 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/25 17:54:18 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** Переделать под двухмерку с пробелами
*/

void create_file_v(t_echo *new, char *line)
{
	int		end;
	char	*name;
	int		i;

	i = 0;
	name = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(name, line, i + 1);
	new->fd = ft_realloc_mass(new->fd, name);
}