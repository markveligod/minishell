/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_of_them.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:53:39 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/02 14:53:40 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	ft_one_of_them(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_one_of_them_mass(char **map, char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_one_of_them(map[i][j], set) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
