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

int				skip_quote(int i, char *line)
{
	if (line[i] == '\"')
	{
		i++;
		while (line[i] && line[i] != '\"')
			i++;
		return (i);
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
		return (i);
	}
	return (i);
}

static int		ft_words(char const *s, char c, char c2)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != c2 && (i == 0 ||
			s[i - 1] == c || s[i - 1] == c2))
		{
			i = skip_quote(i, (char *)s);
			w++;
		}
		i++;
	}
	return (w);
}

static int		ft_symb(char const *s, char c, int i, char c2)
{
	int		symb;
	int		j;

	symb = 0;
	while (s[i] != c && s[i] && s[i] != c2)
	{
		j = skip_quote(i, (char *)s);
		if (i != j)
			symb += j - i - 2;
		i = j;
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

static int		if_quote(int *i, int *symb, char *mass, char *s)
{
	if (s[*i] == '\"')
	{
		*i = *i + 1;
		while (s[*i] != '\"')
		{
			mass[*symb] = s[*i];
			*i = *i + 1;
			*symb = *symb + 1;
		}
		return (1);
	}
	else if (s[*i] == '\'')
	{
		*i = *i + 1;
		while (s[*i] != '\'')
		{
			mass[*symb] = s[*i];
			*i = *i + 1;
			*symb = *symb + 1;
		}
		return (1);
	}
	return (0);
}

char			**line_parse(char const *s, char c, char c2)
{
	char	**mass;
	int		i;
	int		w;
	int		symb;
	int		words;

	words = ft_words(s, c, c2);
	w = 0;
	i = 0;
	if (!s || !(mass = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (w < words)
	{
		symb = 0;
		if (s[i] != c && s[i] != c2 && (i == 0 ||
			s[i - 1] == c || s[i - 1] == c2))
		{
			if ((mass[w] = (char *)malloc(sizeof(char) *
						(ft_symb(s, c, i, c2) + 1))) == NULL)
				return (mass_free(mass));
			if (!(if_quote(&i, &symb, mass[w], (char *)s)))
				while (s[i] != c && s[i] && s[i] != c2)
					mass[w][symb++] = s[i++];
			mass[w++][symb] = '\0';
		}
		i++;
	}
	mass[w] = NULL;
	return (mass);
}
