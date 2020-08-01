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
*/

char		*inplace_env(char *word, char **env, int *j)
{
	int		k;
	char	*name;
	char	*end;
	char	*value;
	int		tmp_j;

	/*
	** Выделяем из строки имя переменной среды
	** В end заносим оставшийся кусочек строки
	*/
	k = 0;
	name = ft_strdup(word + *j + 1);
	while (ft_isalnum(name[k]))
		k++;
	end = ft_strdup(name + k);
	name[k] = '\0';
	/*
	** Ищем в массиве env нужное имя переменной
	*/
	k = 0;
	while (env[k] && ft_strcmp(env[k], name) != 0)
		k++;
	free(name);
	/*
	** Создаем новое слово
	** Заносим туда символы до переменной
	** Соединяем со значением переменной из env
	** Cоединяем с концом строки
	*/
	tmp_j = 0;
	value = (char *)malloc(sizeof(char) * (*j + 1));
	while (tmp_j != *j)
	{
		value[tmp_j] = word[tmp_j];
		tmp_j++;
	}
	value[tmp_j] = '\0';
	if (env[k] && env[++k])
		value = ft_strjoin(value, env[k]);
	*j = ft_strlen(value) - 1;
	value = ft_strjoin(value, end);
	free(word);
	free(end);
	return (value);
}
