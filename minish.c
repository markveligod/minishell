/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:27:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 15:28:54 by ckakuna          ###   ########.fr       */
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
	ptr->cd = NULL;
	ptr->pwd = NULL;
	ptr->exp = NULL;
	ptr->un = NULL;
	ptr->env = NULL;
	ptr->exit = NULL;
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
	init_struct_base(ptr);
	dup_line = ft_strdup(line);
	mass = line_space(line);
	space = line_space_counter(dup_line, ft_mass_len(mass));
	while (mass[i])
	{
		if ((ft_strcmp(";", mass[i]) == 0) || (ft_strcmp("|", mass[i]) == 0))
		{
			ptr->base->flag_base = ft_realloc_mass(ptr->base->flag_base, mass[i]);
			i++;
			continue ;
		}
		if ((ft_strcmp("echo", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_echo(&mass[i], ptr, &space[i]);
		}
		else if ((ft_strcmp("cd", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_cd(&mass[i], ptr);
		}
		else if ((ft_strcmp("pwd", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_pwd(&mass[i], ptr);
		}
		else if ((ft_strcmp("export", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_export(&mass[i], ptr);
		}
		else if ((ft_strcmp("unset", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_unset(&mass[i], ptr);
		}
		else if ((ft_strcmp("env", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_env(&mass[i], ptr);
		}
		else if ((ft_strcmp("exit", mass[i])) == 0)
		{
			ptr->base->ar_base = ft_realloc_mass(ptr->base->ar_base, mass[i]);
			i += parser_exit(&mass[i], ptr);
		}
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
	
	ft_putstr("(^_^)> ");
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
		ft_putstr("(^_^)> ");
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
		** Start test ECHO
		
		int k;
		char **fd;
		char **flag;
		int ct = 1;
		printf("\nStart test ECHO... \n");
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
			ptr.ec = ptr.ec->next;
			ct++;
		}
		printf("End test ECHO... \n\n");
		
		** End Test echo
		*/

		/*
		** Start Test base element
		*/
		printf("\n\nStart test base element... \n");
		int j = 0;
		char **base = ptr.base->flag_base;
		printf("Base element[;][|]: \n");
		while (base[j])
		{
			printf("%d - %s\n", j + 1, base[j]);
			j++;
		}
		j = 0;
		base = ptr.base->ar_base;
		printf("Base command[echo][cd][pwd][...]: \n");
		while (base[j])
		{
			printf("%d - %s\n", j + 1, base[j]);
			j++;
		}
		printf("End test base element... \n\n");
		/*
		** End Test base element
		*/

		/*
		** Start Test cd
		*/
		printf("\nStart test cd... \n");
		int c = 0;
		base = ptr.cd->path;
		cd_command(base);
		printf("CD PATH ARGV: \n");
		if (*base)
		{
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		}
		printf("End test cd... \n\n");
		/*
		** End Test cd
		*/

		/*
		** Start Test pwd
		
		printf("\n\nStart test pwd... \n\n");
		c = 0;
		base = ptr.pwd->arg;
		printf("PWD ARGV: \n");
		if (*base)
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		printf("\n\nEnd test pwd... \n\n");
		
		** End Test pwd
		*/

		/*
		** Start Test export
		
		printf("\n\nStart test export... \n\n");
		c = 0;
		base = ptr.exp->arg;
		printf("export ARGV: \n");
		if (*base)
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		printf("\n\nEnd test export... \n\n");
		
		** End Test export
		*/

		/*
		** Start Test unset
		
		printf("\n\nStart test unset... \n\n");
		c = 0;
		base = ptr.un->arg;
		printf("unset ARGV: \n");
		if (*base)
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		printf("\n\nEnd test unset... \n\n");
		
		** End Test unset
		*/

		/*
		** Start Test env
		
		printf("\n\nStart test env... \n\n");
		c = 0;
		base = ptr.env->arg;
		printf("env ARGV: \n");
		if (*base)
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		printf("\n\nEnd test env... \n\n");
		
		** End Test env
		*/

		/*
		** Start Test exit
		
		printf("\n\nStart test exit... \n\n");
		c = 0;
		base = ptr.exit->arg;
		printf("exit ARGV: \n");
		if (*base)
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		printf("\n\nEnd test exit... \n\n");
		
		** End Test exit
		*/
	}
	return (0);
}
