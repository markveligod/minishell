#include "./minish.h"

void    test_parsing(t_ptr *ptr)
{
	int i;
	int j;
	int k;
	char **fd;
	char **flag;
	int ct;
	char **base;
	int c;

	/*
	** Start Test base element
	
	if (ptr->base != NULL)
	{
		t_base *bas;
		printf("\n_________________________\n");
		printf("Start test base element... \n");
		j = 0;
		base = ptr->base->flag_base;
		printf("Base element[;][|]: \n");
		while (base[j])
		{
			printf("%d - %s\n", j + 1, base[j]);
			j++;
		}
		j = 0;
		base = ptr->base->ar_base;
		printf("Base command[echo][cd][pwd][...]: \n");
		while (base[j])
		{
			printf("%d - %s\n", j + 1, base[j]);
			j++;
		}
		j = 0;
		base = ptr->is_env;
		printf("Base env: \n");
		while (base[j])
		{
			printf("%d - %s\n", j + 1, base[j]);
			j++;
		}
		printf("End test base element...\n");
		printf("_________________________\n\n");
	}
	
	** End Test base element
	*/


	/*
	** Start test commands	
	*/
	if (ptr->command != NULL)
	{
		ct = 1;
		printf("\nStart test commands... \n");
		t_command *com;
		com = ptr->command;
		while (com)
		{
			base = com->args;
			printf("\nNumber: #%d\n", ct);
			printf("Command: %s\n", com->command);
			printf("ARGS: \n");
			c = 0;
			if (*base)
			{
				while (base[c])
				{
					printf("%d - %s\n", c + 1, base[c]);
					c++;
				}
			}
			fd = com->filename;
			k = 0;
			while (fd[k])
			{
				printf("File: #%d Name: %s\n", k+1, fd[k]);
				k++;
			}
			flag = com->flag_v;
			k = 0;
			while (flag[k])
			{
				printf("Flag: #%d - %s\n", k+1, flag[k]);
				k++;
			}
			printf("Doing:\n");
			do_command(com, ptr);
			printf("\n");
			com = com->next;
			ct++;
		}
		printf("End test command... \n\n");
	}
	/*
	** End test commands
	*/
}

void    check_split(char **mass, char *dup_line, char *line, char **space)
{
    /*
	** checking split
	int i = 0;
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
}

/*
int		check_nnn(char **str, t_echo *new)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp("-n", str[i]) != 0)
			break;
		else
		{
			new->flag_n = 1;
			i++;
		}
	}
	return (i);
}
*/