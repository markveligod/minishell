/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:58:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/25 17:54:23 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** копия create_file_v.c
*/

void create_flag_v(t_echo *new, char *line)
{
	int		end;
	char	*name;
	int		i;

	i = 0;
	name = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(name, line, i + 1);
	new->flag_v = ft_realloc_mass(new->flag_v, name);
}