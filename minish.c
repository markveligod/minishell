/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 12:00:33 by ckakuna          ###   ########.fr       */
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
	ft_free_array(mass);
	ft_free_array(space);
}

/*
** Функция цикличного чтения строки
*/

void	read_input(t_ptr *ptr)
{
	char *line;

	while (1)
	{
		ft_putstr("(^_^)> ");
		get_next_line(&line);
		check_param(line, ptr);
		test_parsing(ptr);
		clear_malloc(ptr);
	}
}

int		main(int ac, char **av, char **env)
{
	t_ptr 	ptr;

	init_struct_ptr(&ptr);
	ptr.is_env = parser_env(env);
	read_input(&ptr);
	return (0);
}
