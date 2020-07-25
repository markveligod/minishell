/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/25 17:58:06 by ckakuna          ###   ########.fr       */
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

	i = 0;
	/*
	** checking split
	*/
	/*mass = line_space(line);
	while (mass[i] != NULL)
		printf("%s\n", mass[i++]);
	*/
	/*
	** end of checking
	*/
	init_struct_ptr(ptr);
	mass = line_space(line);
	/*while (mass[i])
	{
		if ((ft_strcmp("echo", mass[i])) == 0)
			i += parser_echo(&mass[i], ptr);
		else
			i++;
	}*/
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
		int count = 1;
		while (ptr.ec)
		{
			printf("List: #%d\n", count);
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
			ptr.ec = ptr.ec->next;
			count++;
		}
	}
	return (0);
}
