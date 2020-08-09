/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:26:32 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/02 16:57:24 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static int		ft_words(char const *s, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			w++;
		i++;
	}
	return (w);
}

static int		ft_symb(char const *s, char c, int i)
{
	int		symb;

	symb = 0;
	while (s[i] != c && s[i])
	{
		i++;
		symb++;
	}
	return (symb);
}

static void		*mass_free(char **mass)
{
	int		w;

	w = 0;
	while (mass[w])
		free(mass[w++]);
	free(mass);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**mass;
	int		i;
	int		w;
	int		symb;

	if (!s || !(mass = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (NULL);
	w = 0;
	i = 0;
	while (w < ft_words(s, c))
	{
		symb = 0;
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			if ((mass[w] = (char *)malloc(sizeof(char) *
						(ft_symb(s, c, i) + 1))) == NULL)
				return (mass_free(mass));
			while (s[i] != c && s[i])
				mass[w][symb++] = s[i++];
			mass[w++][symb] = '\0';
		}
		i++;
	}
	mass[w] = NULL;
	return (mass);
}
