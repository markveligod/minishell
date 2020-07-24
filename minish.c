/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 10:32:38 by ckakuna          ###   ########.fr       */
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

void	init_list_echo(t_ptr *ptr)
{
	if (!(ptr->ec = (t_echo *)malloc(sizeof(t_echo))));
		clear_malloc();
	ptr->ec->flag_n = 0;
	ptr->ec->flag_v = 0;
	ptr->ec->flag_vv = 0;
	ptr->ec->flag_dotcomma = 0;
	ptr->ec->flag_dollar = 0;
}

void 	parser_echo(char **line, t_ptr *ptr)
{
	int i;
	
	init_list_echo(ptr);

}

int		check_pipe(char **line)
{
	int i;
	int pipe;

	i = 0;
	pipe = 0;
	while (line[i] != NULL)
	{
		if (!(ft_strcmp(line[i], "|")))
			pipe = i;
		i++;
	}
	return (pipe);
}

void	check_param(char **line, t_ptr *ptr)
{
	int i;

	i = check_pipe(line);
	printf("%d\n", i);
	while (line[i])
	{
		if (ft_strcmp("echo", line[i]))
			parser_echo(&line[i], ptr);
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
			if (!(mass = ft_split(line, ' ')))
				error("Malloc error");
			check_param(mass, &ptr);
		}
		free(line);
		ft_putstr("Ok\n");
	}
	return (0);
}