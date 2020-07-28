/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/27 09:36:15 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** Проверяет параметры в строке
*/

void	check_param(char *line, t_ptr *ptr)
{
	int		i;
	char 	**mass;
	char	**space;
	char	*dup_line;

	i = 0;
	init_struct_ptr(ptr);
	init_struct_base(ptr);
	dup_line = ft_strdup(line);
	mass = line_space(line, ptr);
	space = line_space_counter(dup_line, ft_mass_len(mass), ptr);
	while (mass[i])
	{
		if ((ft_strcmp(";", mass[i]) == 0) || (ft_strcmp("|", mass[i]) == 0))
		{
			ptr->base->flag_base = ft_realloc_mass(ptr->base->flag_base, mass[i]);
			i++;
		}
		else
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_command(&mass[i], ptr, space);
		}
	}
}

/*
** Функция для чтения из строки еще раз возвращает line
*/

char	*read_line(char *line)
{	
	ft_putstr("(^_^)> ");
	get_next_line(&line);
	return (line);
}

int		main(void)
{
	int 	count;
	char 	*line;
	t_ptr 	ptr;

	while (1)
	{
		line = read_line(line);
		check_param(line, &ptr);
		test_parsing(&ptr);
		//free(line);
	}
	return (0);
}
