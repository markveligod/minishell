/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:26:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/27 09:33:58 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

# include <stdio.h> //delete

typedef struct			s_base
{
	char				**flag_base;
	char				**ar_base;
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


/*
** _____________________prototype srcs__________________________
*/

/*
** main functions
*/
void					clear_malloc();
char					*read_line(char *line);
int						main(void);
void					error(char *str, t_ptr *ptr);
int						parser_command(char **line, t_ptr *ptr, char **spaces);

/*
** parsing input line
*/
char					**line_parse(char const *s, char c, char c2);
char					**line_space(char *line, t_ptr *ptr);
char					**line_space_counter(char *line, int len, t_ptr *ptr);
int						line_skip_quote(int i, char *line, t_ptr *ptr);

/*
** initialization of structures and lists
*/
void					init_struct_ptr(t_ptr *ptr);
void					init_struct_base(t_ptr *ptr);
t_command				*init_list_command(t_command *new);


/*
** commands (srcs/commands)
*/
void					do_command(t_command *command);
void					cd_command(t_command *command);
void					pwd_command(t_command *command);
int						external_command(t_command *command);

/*
** TEST'S
*/
void			    	test_parsing(t_ptr *ptr);
void  					test_clear_malloc(t_ptr *ptr);
void					check_split(char **mass, char *dup_line, char *line, char **space);

#endif