/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:53:16 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/02 14:53:21 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	ft_mass_len(char **mass)
{
	int i;

	i = 0;
	while (mass[i] != NULL)
		i++;
	return (i);
}
