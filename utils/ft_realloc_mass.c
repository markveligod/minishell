/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_mass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:45:23 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/15 17:45:25 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	**ft_realloc_mass(char **map, char *line)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_mass_len(map) + 2));
	while (map[i] != NULL)
	{
		result[i] = ft_strdup(map[i]);
		i++;
	}
	result[i++] = ft_strdup(line);
	result[i] = NULL;
	i = 0;
	ft_free_array(map);
	return (result);
}
