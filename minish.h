/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:26:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/22 13:11:54 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>

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
	char				base;
	struct s_command	*next;
}						t_command;

typedef struct			s_ptr
{
	t_base				*base;
	t_command			*command;
	char				**is_env;
	char				**is_export;
	int					*mass_red;
	char				***mass;
	t_command			**com_mass;
}						t_ptr;

/*
** Global value
*/

int						g_flag;
char					*g_pwd;
char					*g_curr_err;
int						g_signal;

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
int						ft_strchr(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					*ft_strdup(const char *s1);
char					**ft_realloc_mass(char **map, char *line);
int						ft_mass_len(char **mass);
void					ft_free_array(char **arr);
void					ft_putstr_fd(char *s, int fd);
int						ft_one_of_them(char c, char *str);
int						ft_one_of_them_mass(char **map, char *set);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
char					*ft_delete_array_elem(char *arr, int i);
void					ft_lst_add_back(t_command **lst, t_command *new);
char					**ft_split(char const *s, char c);
char					*ft_substr(char *s, int start, int len);

/*
** _____________________prototype srcs__________________________
*/

/*
** main functions
*/
void					clear_malloc();
char					*read_line(char *line);
void					read_input(t_ptr *ptr);
void					error(char *str, t_ptr *ptr);
void					write_in_file(t_command *command, char *line);
void					errno_error(char *com_name, errno_t error_num);

/*
** parsing input line
*/

void					line_parsing(char *line, t_ptr *ptr);
char					**line_split_into_words(char *line, char ***spaces);
int						line_parse_by_command(char **line, t_ptr *ptr,
						char **spaces);
char					*inplace_env(char *word, char **env, int *j);
char					**parser_env(char **env);
char					*modify_word(char *word, char **env);
void					line_check(char **line);
int						line_skip_quote(int i, char *line);

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
int						cd_command(t_command *command, t_ptr *ptr);
void					pwd_command(t_command *command);
void					echo_command(t_command *command);
void					env_command(char **env, t_command *command);
void					export_command(t_ptr *ptr, t_command *command);
void					export_com_here(t_ptr *ptr, t_command *command, int i);
int						export_equal_args(char **args);
char					**export_add_args(char **env, char *value);
char					**export_change_env(char **env, char *value);
int						export_check_args(char **env, char *value);
void					unset_command(t_ptr *ptr, t_command *command);
void					exit_command(t_ptr *ptr);
void					curr_err_command();
void					redirect_command(t_command *command);

/*
** extarnal command
*/

void					external_command(t_command *command, char **env);
void					file_command(t_command *command, char **env);
void					fork_redirect(char *file_name, char *flag, char **mass);
void					fork_run(t_command *command, char **mass);
void					run_forks(int flag, t_command *command, char **mass);
int						check_stat(t_command *command, char *filename,
						int name_flag);
char					*relative_path(char *path);

/*
** TEST'S
*/

void					test_parsing(t_ptr *ptr);
void					test_clear_malloc(t_ptr *ptr);
void					check_split(char **mass, char *dup_line, char *line,
						char **space);

/*
** NEW FOR PIPES
*/

char					**external_mass(t_command *command, char **env);
void					run_commands(t_ptr *ptr);
void					clear_mass_com(t_ptr *ptr, int count);
int						size_pipe_in_line(t_command *com);
void					init_mass_command(t_ptr *ptr, int count);
t_command				*put_param_in_mass(t_command *com, t_ptr *ptr);
void					pipe_commands(t_ptr *ptr, int size);
void					pipe_redirect_fork(int file, char **mass,
						t_command *com_mass, t_ptr *ptr);
int						if_internal_command(t_command *command);
int						get_fd(t_command *command);

#endif
