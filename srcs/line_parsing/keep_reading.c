/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:29:46 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/03 11:29:48 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	keep_reading(char *line)
{
	char	*newline;
	int		i;

	ft_putstr("quote $> ");
	get_next_line(&newline);
	line = ftstrjoin(line, newline);
}
