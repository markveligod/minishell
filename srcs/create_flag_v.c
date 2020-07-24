/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:58:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 16:54:23 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** копия create_file_v.c
*/

void create_flag_v(t_ptr *ptr, char *line)
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
	ptr->ec->flag_v = ft_realloc_mass(ptr->ec->flag_v, name);
}