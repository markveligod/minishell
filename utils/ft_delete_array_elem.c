/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_array_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:30:20 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/01 17:30:59 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*ft_delete_array_elem(char *arr, int i)
{
	char	*temp;
	int		j;

	temp = (char *)malloc(sizeof(char *) * ft_strlen(arr));
	j = 0;
	while (j != i)
	{
		temp[j] = arr[j];
		j++;
	}
	i++;
	while (arr[i])
	{
		temp[j++] = arr[i++];
	}
	temp[j] = '\0';
	free(arr);
	return (temp);
}
