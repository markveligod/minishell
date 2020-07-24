/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 13:03:22 by ckakuna          ###   ########.fr       */
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
	ptr->ec->flag_dotcomma = 0;
	ptr->ec->flag_dollar = 0;
}

int 	parser_echo(char *line, t_ptr *ptr, )
{
	int i;
	int fd;
	
	i = 4;
	init_list_echo(ptr);
	i += check_nnn(&line[i], ptr);
	while (line[i] && line[i] != '|' && line[i] != ';')
	{
		if (line[i] == '>' && line[i + 1] != '>')
		{
			if (line[i + 1] == '|' || line[i + 1] == ';')
				error("Syntex error");
			else 
				fd = create_file_v(ptr, line[++i]);
			i += 2;
			continue ;
		}
		if (ft_strcmp("<", line[i]) == 0)
		{
			fd = 0;
			i += 2;
			continue ;
		}
		ptr->ec->line = ft_strjoin(&line[i]);
	}

}

void	check_param(char *line, t_ptr *ptr)
{
	int i;
	char ch;

	i = 0;
	while (line[i])
	{	
		if (line[i] == 'e' && line[i + 1] == 'c' && line[i + 2] == 'h' && line[i + 3] == 'o')
			i += parser_echo(&line[i], ptr, ft_strchr(&line[i]));
		if (line[i] == 'c' && line[i + 1] == 'd')
			i += parser_cd(&line[i], ptr, ft_strchr(&line[i]));
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
			check_param(line, &ptr);
		}
		free(line);
	}
	return (0);
}
