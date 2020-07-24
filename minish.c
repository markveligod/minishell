/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 08:53:59 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int 	parser_echo(char *line)
{
	int i;

	i = 4;
	while (line[i] == ' ')
		i++;
	
	return (i);
}

void	check_param(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'e' && line[i + 1] == 'c' && line[i + 2] == 'h' && line[i + 3] == 'o')
			i += parser_echo(&line[i]);
		i++;
	}
}
#hello
int		main(void)
{
	int count;
	char *line;
	char **mass;

	ft_putstr("(｡◕‿◕｡✿) \n");
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
		}
		free(line);
		ft_putstr("Ok\n");
	}
	return (0);
}