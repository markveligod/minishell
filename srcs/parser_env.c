/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:57:04 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/29 07:55:32 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

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
	{
		ft_putstr_fd("Allocation error!\n", 0);
		exit(1);
	}
	new_env[0] = NULL;
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		env[i][j] = '\0';
		temp = ft_strdup(env[i]);
		new_env = ft_realloc_mass(new_env, temp);
		j++;
		free(temp);
		temp = ft_strdup(&env[i][j]);
		new_env = ft_realloc_mass(new_env, temp);
		free(temp);
		i++;
	}
	return (new_env);
}