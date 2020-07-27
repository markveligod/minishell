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
		** Start test ECHO	
		
		ct = 1;
		printf("\nStart test ECHO... \n");
		while (ptr->ec)
		{
			printf("List: #%d\n", ct);
			printf("Str: %s\n", ptr->ec->line);
			printf("Flag -n: %d\n", ptr->ec->flag_n);
			fd = ptr->ec->fd;
			k = 0;
			while (fd[k])
			{
				printf("File: #%d Name: %s\n", k+1, fd[k]);
				k++;
			}
			flag = ptr->ec->flag_v;
			k = 0;
			while (flag[k])
			{
				printf("Flag: #%d - %s\n", k+1, flag[k]);
				k++;
			}
			ptr->ec = ptr->ec->next;
			ct++;
		}
		printf("End test ECHO... \n\n");
		
		** End Test echo
		*/


		/*
		** Start Test base element
		
		printf("\n\nStart test base element... \n");
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
		printf("End test base element... \n\n");
		
		** End Test base element
		*/


		/*
		** Start Test cd
		
		printf("\nStart test cd... \n");
		c = 0;
		base = ptr->cd->path;
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
		
		** End Test cd
		*/


		/*
		** Start Test pwd
		
		printf("\n\nStart test pwd... \n\n");
		c = 0;
		base = ptr->pwd->arg;
		pwd_command(base);
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
		base = ptr->exp->arg;
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
		base = ptr->un->arg;
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
		base = ptr->env->arg;
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
		base = ptr->exit->arg;
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


		/*
		** Start test external
		
		printf("\n\n_______________________\n");
		printf("Start test external... \n\n");
		c = 0;
		base = ptr->external->arg;
		printf("external ARGV: \n");
		if (*base)
			while (base[c])
			{
				printf("%d - %s\n", c + 1, base[c]);
				c++;
			}
		printf("\nEnd test env...\n");
		printf("_______________________\n\n");

		**
		*/
}

void    test_clear_malloc(t_ptr *ptr)
{

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
** testing fork

#define _GNU_SOURSE
int main(void)
{
	pid_t pid;
	pid_t wpid;
	int count;
	char *line;
	t_ptr ptr;
	int status;

	while (1)
	{
		line = read_line(line);
		//check_param(line, &ptr);
		pid = fork();
		if (pid == 0)
		{
			char *args[] = {"/bin/ls", NULL};
			execve("/bin/ls", args, NULL);

		}
		else
		{
				wpid = waitpid(pid, &status, WUNTRACED);
		}

		//test_parsing(&ptr);
		//free(line);
	}
}

** end of testing fork
*/