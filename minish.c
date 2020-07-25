/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/25 20:53:00 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

/*
** clear malloc to go main() !!!
*/

void	clear_malloc()
{
	return ;
}

/*
** иницилизирует структуру ptr
*/

void	init_struct_ptr(t_ptr *ptr)
{
	ptr->ec = NULL;
	ptr->base = NULL;
}

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

	/*
	** checking split
	
	dup_line = ft_strdup(line);
	mass = line_space(line);
	while (mass[i] != NULL)
		printf("%s\n", mass[i++]);
	space = line_space_counter(dup_line, ft_mass_len(mass));
	i = 0;
	while (space[i] != NULL)
	{
		printf("%d-|%s|\n", i, space[i]);
		i++;
	}
	
	** end of checking
	*/

	init_struct_ptr(ptr);
	//init_struct_base(ptr);
	dup_line = ft_strdup(line);
	mass = line_space(line);
	space = line_space_counter(dup_line, ft_mass_len(mass));
	while (mass[i])
	{
		/*if ((ft_strcmp(";", mass[i]) == 0) || (ft_strcmp("|", mass[i]) == 0))
		{
			//ptr->base->flag_base = ft_realloc_mass(ptr->base->flag_base, mass[i]);
			i++;
			continue ;
		}*/
		if ((ft_strcmp("echo", mass[i])) == 0)
			i += parser_echo(&mass[i], ptr, &space[i]);
		else
			i++;
	}
}

/*
** Функция для чтения из строки еще раз возвращает line
*/

char	*read_line(char *line)
{
	int count;
	
	ft_putstr("> ");
	if ((count = get_next_line(&line)) == (-1))
		error("I couldn't read it");
	return (line);
}

int		main(void)
{
	int 	count;
	char 	*line;
	t_ptr 	ptr;

	while (1)
	{
		ft_putstr("> ");
		if ((count = get_next_line(&line)) == (-1))
		{
			error("I couldn't read it");
			continue;
		}
		else
		{
			check_param(line, &ptr);
		}
		//free(line);
		/*
		** Тестирование листов ECHO
		*/
		int k;
		char **fd;
		char **flag;
		int ct = 1;
		while (ptr.ec)
		{
			printf("List: #%d\n", ct);
			printf("Str: %s\n", ptr.ec->line);
			printf("Flag -n: %d\n", ptr.ec->flag_n);
			fd = ptr.ec->fd;
			k = 0;
			while (fd[k])
			{
				printf("File: #%d Name: %s\n", k+1, fd[k]);
				k++;
			}
			flag = ptr.ec->flag_v;
			k = 0;
			while (flag[k])
			{
				printf("Flag: #%d - %s\n", k+1, flag[k]);
				k++;
			}
			printf("Flag base: %c\n", ptr.ec->flag_base);
			ptr.ec = ptr.ec->next;
			ct++;
		}
		/*if (ptr.base)
		{
			int j = 0;
			char **base = ptr.base->flag_base;
			printf("Base element[;][|]: \n");
			while (base[j])
			{
				printf("%s\n", base[j]);
				j++;
			}
		}*/
	}
	return (0);
}
