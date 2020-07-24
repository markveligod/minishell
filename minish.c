/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 14:30:11 by ckakuna          ###   ########.fr       */
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
	if (!ptr->ec)
		if (!(ptr->ec = (t_echo *)malloc(sizeof(t_echo))));
			clear_malloc();
	ptr->ec->flag_n = 0;
}

int		check_nnn(char *str, t_ptr *ptr)
{
	int i;

	i = 0;
	while (str[i] == ' ')
	{
		if (str[i + 1] == '-' && str[i + 2] == 'n')
		{
			ptr->ec->flag_n = 1;
			i += 3;
		}
		else
			i++;
	}
	return (i);
}

int 	parser_echo(char *line, t_ptr *ptr, int j)
{
	int i;
	int fd;

	i = 4;
	init_list_echo(ptr);
	i += check_nnn(&line[i], ptr);
	while (line[i] && i != j)
	{
		if (line[i] == '>' && line[i + 1] != '>')
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (i == j)
				error("Syntex error");
			else
				create_file_v(ptr, &line[i]);
			while (line[i] != ' ' && i != j && line[i] != '>' && line[i] != '<')
				i++;
			continue ;
		}
		if (line[i] == '>' && line[i + 1] == '>')
		{
			i += 2;
			while (line[i] == ' ')
				i++;
			if (i == j)
				error("Syntex error");
			else
				create_file_v(ptr, line[i]);
			while (line[i] != ' ' && i != j && line[i] != '>' && line[i] != '<')
				i++;
			continue ;
		}
		if (line[i] == '<' && line[i + 1] != '<')
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (i == j)
				error("Syntex error");
			else
				create_file_v(ptr, "0");
			while (line[i] != ' ' && i != j && line[i] != '>' && line[i] != '<')
				i++;
			continue ;
		}
		ptr->ec->line = ft_strjoin(ptr->ec->line, line[i]);
	}
	return (i);
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
//		if (line[i] == 'c' && line[i + 1] == 'd')
//			i += parser_cd(&line[i], ptr, ft_strchr(&line[i]));
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
		printf("Str: %s\n", ptr.ec->line);
	}
	return (0);
}
