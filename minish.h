/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:26:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/24 09:49:45 by ckakuna          ###   ########.fr       */
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
}					t_echo;

/*
** prototype utils
*/

void				ft_putstr(char *str);
char				*ft_strjoin(char *remains, char *buffer);
int					ft_strlen(char *str);
int					get_next_line(char **line);
void				error(char *str);
int					ft_strncmp(const char *str1, const char *str2);

#endif