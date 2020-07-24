/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:26:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 10:20:41 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

typedef struct		s_echo
{
	char			*line;
	int				flag_n;
	int				flag_v;
	int 			flag_vv;
	int				flag_dollar;
	int				flag_dotcomma;
}					t_echo;

typedef struct		s_ptr
{
	t_echo			*ec;
}					t_ptr;


/*
** prototype utils
*/

void				ft_putstr(char *str);
char				*ft_strjoin(char *remains, char *buffer);
int					ft_strlen(char *str);
int					get_next_line(char **line);
void				error(char *str);
int					ft_strcmp(const char *str1, const char *str2);
char				**ft_split(char const *s, char c);

#endif