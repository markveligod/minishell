/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:37:30 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/22 11:37:32 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

/*
** Функция для парсинга переменных окружения в структуру base
*/

char		**parser_env(char **env)
{
	char	**new_env;
	int		i;
	int		j;
	char	*temp;

	if (!(new_env = (char **)malloc(sizeof(char *) * (ft_mass_len(env) + 1))))
		exit(1);
	new_env[0] = NULL;
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		env[i][j] = '\0';
		temp = ft_strdup(env[i]);
		new_env = ft_realloc_mass(new_env, temp);
		free(temp);
		temp = ft_strdup(&env[i][++j]);
		new_env = ft_realloc_mass(new_env, temp);
		free(temp);
	}
	return (new_env);
}
