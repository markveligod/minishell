/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 16:51:25 by ckakuna          ###   ########.fr       */
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

void	check_param(char **line, t_ptr *ptr)
{
	int i;

	i = 0;
	/*
	** checking split
	*/
	ft_split_all_line(line);
	printf("%s\n", line);
	/*
	** end of checking
	*/

	while (line[i])
	{
		if (ft_strncmp("echo", line[i]) == 0)
			i += parser_echo(&line[i], ptr);
		i++;
	}
}

int		main(void)
{
	int 	count;
	char 	*line;
	char 	**mass;
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
			check_param(mass, &ptr);
		}
		free(line);
		printf("Str: %s\n", ptr.ec->line);
	}
	return (0);
}
