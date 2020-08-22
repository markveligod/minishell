/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_inplace_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:53:25 by leweathe          #+#    #+#             */
/*   Updated: 2020/07/30 08:53:28 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** _________________________________________________________
** Расшифровывает переменную среды (из имени в ее значение);
** _________________________________________________________
** inplace_env - функция по расшифровке переменной среды
** - выделяет из строки имя переменной
** - отделяет конец строки (после переменной)
** - вызывает create_string
** - добавляет к полученной строке конец
**
** create_string - вспомогательная функция
** - находит в env соответствующее значение
** - записывает в строку ее начало (до переменной среды)
** - добавляет в нее расшифрованную переменную
*/

char		*create_string(int *j, char *word, char *name, char **env)
{
	int		tmp_j;
	char	*value;
	int		k;
	char	flag;

	k = 0;
	tmp_j = 0;
	flag = name[0];
	while (env[k] && ft_strcmp(env[k], name) != 0)
		k++;
	free(name);
	value = (char *)malloc(sizeof(char) * (*j + 1));
	while (tmp_j != *j)
	{
		value[tmp_j] = word[tmp_j];
		tmp_j++;
	}
	value[tmp_j] = '\0';
	if (flag == '?')
		value = ft_strjoin(value, g_curr_err);
	else if (env[k] && env[++k])
		value = ft_strjoin(value, env[k]);
	return (value);
}

char		*inplace_env(char *word, char **env, int *j)
{
	int		k;
	char	*name;
	char	*end;
	char	flag;
	char	*value;

	k = 0;
	name = ft_strdup(word + *j + 1);
	flag = name[0];
	if (name[k] == '?')
		k++;
	else
		while (ft_isalnum(name[k]))
			k++;
	end = ft_strdup(name + k);
	name[k] = '\0';
	value = create_string(j, word, name, env);
	*j = ft_strlen(value);
	value = ft_strjoin(value, end);
	free(word);
	free(end);
	return (value);
}
