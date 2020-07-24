/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:39:31 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/24 16:53:56 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** Переделать под двухмерку с пробелами
*/

void create_file_v(t_ptr *ptr, char *line)
{
	int		end;
	char	*name;
	int		i;

	i = 0;
	end = ft_strchr(line);
	while (i < end && line[i] != ' ')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(name, line, i + 1);
	ptr->ec->fd = ft_realloc_mass(ptr->ec->fd, name);
}