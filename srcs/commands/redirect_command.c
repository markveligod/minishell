/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:26:07 by leweathe          #+#    #+#             */
/*   Updated: 2020/08/04 20:26:08 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	redirect_command(t_command *command)
{
	char	*bigline;
	char	*line;

	bigline = ft_strdup("");
	while (get_next_line(&line) > 0)
		bigline = ft_strjoin(bigline, line);
	//!!!!
}
