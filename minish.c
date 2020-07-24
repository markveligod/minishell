/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 16:29:32 by ckakuna          ###   ########.fr       */
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
	ptr->ec->fd = (char **)malloc(sizeof(char *) * 1);
	ptr->ec->flag_v = (char **)malloc(sizeof(char *) * 1);
	ptr->ec->fd[0] = NULL;
	ptr->ec->flag_v[0] = NULL;
	ptr->ec->flag_n = 0;
}

int		check_nnn(char **str, t_ptr *ptr)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp("-n", str[i]) != 0)
			break;
		else
		{
			ptr->ec->flag_n = 1;
			i++;
		}
	}
	return (i);
}

int 	parser_echo(char **line, t_ptr *ptr)
{
	int i;
	t_echo new;

	i = 1;
	new = init_list_echo(ptr);
	i += check_nnn(&line[i], ptr);
	while (line[i])
	{
		if (ft_strcmp(";", line[i]) == 0)
		{
			break ;
		}
		if (ft_strcmp("|", line[i]) == 0)
		{
			break ;
		}
		if (ft_strcmp(">>", line[i]) == 0 || ft_strcmp(">", line[i]) == 0 || ft_strcmp("<", line[i]) == 0)
		{
			create_flag_v(ptr, line[i]);
			if (!line[i + 1] || ft_strcmp("|", line[i + 1]) == 0 || ft_strcmp(";", line[i + 1]) == 0)
				error("Syntex error");
			else
				create_file_v(ptr, line[++i]);
			i++;
			continue ;
		}
		ptr->ec->line = ft_strjoin(ptr->ec->line, line[i]);
	}
	return (i);
}

void	check_param(char **line, t_ptr *ptr)
{
	int i;

	i = 0;
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
