/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/25 16:03:31 by ckakuna          ###   ########.fr       */
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

void	check_param(char *line, t_ptr *ptr)
{
	int i;
<<<<<<< HEAD
	char **mass;
=======
	char 	**mass;
>>>>>>> ea210a137bf014c4d1e28c763cbb02407c8346a6

	i = 0;
	/*
	** checking split
	*/
<<<<<<< HEAD
	mass = line_space(line);
	while (mass[i] != NULL)
		printf("%s\n", mass[i++]);
	/*
	** end of checking
	*/

	while (line[i])
=======
	mass = ft_split_all_line(line);
	while (mass[i])
	{
		printf("%s\n", mass[i]);
		i++;
	}
	/*
	** end of checking
	*/

	while (line[i])
>>>>>>> ea210a137bf014c4d1e28c763cbb02407c8346a6
	{
		if (ft_strncmp("echo", line[i]) == 0)
			i += parser_echo(&line[i], ptr);
		i++;
<<<<<<< HEAD
	}
=======
	}
>>>>>>> ea210a137bf014c4d1e28c763cbb02407c8346a6
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
			continue ;
		}
		else
		{
			check_param(line, &ptr);
		}
		//free(line);
		//printf("Str: %s\n", ptr.ec->line);
	}
	return (0);
}
