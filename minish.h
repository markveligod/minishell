/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:26:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/25 17:58:18 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

# include <stdio.h> //delete

typedef struct		s_echo
{
	char			**fd;
	char			*line;
	int				flag_n;
	char			**flag_v;
	struct s_echo	*next;
}					t_echo;

typedef struct		s_base
{
	char			**flag_base;
}					t_base;

typedef struct		s_ptr
{
	t_echo			*ec;
	t_base			*base;
}					t_ptr;


/*
** prototype utils
*/
int					get_next_line(char **line);
void				ft_putstr(char *str);
char				*ft_strjoin(char *remains, char *buffer);
int					ft_strlen(char *str);
int					get_next_line(char **line);
int					ft_strcmp(char *str1, char *str2);
char				**ft_split(char const *s, char c);
int 				ft_strchr(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				**ft_realloc_mass(char **map, char *line);
int					ft_mass_len(char **mass);
void				ft_free_array(char **arr);

/*
** prototype srcs
*/

char				**line_parse(char const *s, char c, char c2);
char				**line_space(char *line);
int					line_skip_quote(int i, char *line);
void 				create_file_v(t_echo *new, char *line);
void 				create_flag_v(t_echo *new, char *line);
void				error(char *str);
int 				parser_echo(char **line, t_ptr *ptr);
void				clear_malloc();
int					main(void);

#endif