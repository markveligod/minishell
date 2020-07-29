/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:26:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 11:00:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

#include <stdio.h> //delete

typedef struct			s_base
{
	char				**flag_base;
	char				**ar_base;
	char				**is_env;
}						t_base;

typedef struct			s_command
{
	char				*command;
	char				**args;
	char				**spaces;
	char				**filename;
	char				**flag_v;
	struct s_command	*next;
}						t_command;

typedef struct			s_ptr
{
	t_base				*base;
	t_command			*command;
}						t_ptr;


/*
** _____________________prototype utils__________________________
*/
int						get_next_line(char **line);
void					ft_putstr(char *str);
char					*ft_strjoin(char *remains, char *buffer);
char					*ftstrjoin(char *remains, char *buffer);
int						ft_strlen(char *str);
int						get_next_line(char **line);
int						ft_strcmp(char *str1, char *str2);
char					**ft_split(char const *s, char c);
int 					ft_strchr(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					*ft_strdup(const char *s1);
char					**ft_realloc_mass(char **map, char *line);
int						ft_mass_len(char **mass);
void					ft_free_array(char **arr);
void					ft_putstr_fd(char *s, int fd);


/*
** _____________________prototype srcs__________________________
*/

/*
** main functions
*/
void					clear_malloc();
char					*read_line(char *line);
//int						main(void);
void					error(char *str, t_ptr *ptr);
int						parser_command(char **line, t_ptr *ptr, char **spaces);
void					write_in_file(t_command *command, char *line);
void					errno_error(char *com_name, errno_t error_num);

/*
** parsing input line
*/
char					**line_parse(char const *s, char c, char c2);
char					**line_space(char *line, t_ptr *ptr);
char					**line_space_counter(char *line, int len, t_ptr *ptr);
int						line_skip_quote(int i, char *line, t_ptr *ptr);
char					**parser_env(char **env);

/*
** initialization of structures and lists
*/
void					init_struct_ptr(t_ptr *ptr);
void					init_struct_base(t_ptr *ptr);
t_command				*init_list_command(t_command *new);


/*
** commands (srcs/commands)
*/
void					do_command(t_command *command, t_ptr *ptr);
void					cd_command(t_command *command);
void					pwd_command(t_command *command);
void					echo_command(t_command *command);
int						external_command(t_command *command);
void					env_command(char **env);
void					export_command(t_ptr *ptr, t_command *t_command);
void					unset_command(t_ptr *ptr, t_command *t_command);
void					exit_command(t_ptr *ptr);

/*
** TEST'S
*/
void			    	test_parsing(t_ptr *ptr);
void  					test_clear_malloc(t_ptr *ptr);
void					check_split(char **mass, char *dup_line, char *line, char **space);

#endif