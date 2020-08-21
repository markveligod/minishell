/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curr_err_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:25:24 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/21 15:29:13 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	curr_err_command(void)
{
	char *str;

	str = ft_strdup("minish: command not found: ");
	str = ft_strjoin(str, g_curr_err);
	ft_putstr(str);
	free(str);
	g_curr_err = "127";
}
