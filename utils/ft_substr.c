/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:14:14 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/02 13:20:40 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*subs;
	int		i;
	int		length;

	i = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s) - start;
	if (length <= 0)
		length = 0;
	else if (length > len)
		length = len;
	subs = (char *)malloc(sizeof(char) * (length + 1));
	if (subs == NULL)
		return (NULL);
	while (length--)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
