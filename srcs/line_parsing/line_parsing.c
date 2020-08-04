/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:30:04 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/01 19:30:29 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** _________________________________________________
**            Парсинг входной строки.
** _________________________________________________
** На выходе лист с командами, флагами и аргументами
*/

void		line_parsing(char *line, t_ptr *ptr)
{
	char 	**mass;
	int		i;
	int		j;
	char	**spaces;

	init_struct_base(ptr);
	line_check(&line);
	mass = line_split_into_words(line, &spaces);
	i = 0;
	while (mass[i])
	{
		if ((ft_strcmp(";", mass[i]) == 0 || ft_strcmp("|", mass[i]) == 0))
		{
			if (i == 0 || ((ft_strcmp(";", mass[i - 1]) == 0 ||
				ft_strcmp("|", mass[i - 1]) == 0)))
				ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, "\'");
			ptr->base->flag_base = ft_realloc_mass(ptr->base->flag_base, mass[i]);
			i++;
		}
		else
			i += line_parse_by_command(&mass[i], ptr, spaces);
	}
	ft_free_array(mass);
	ft_free_array(spaces);
}
