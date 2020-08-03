/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curr_err_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 10:25:24 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/03 10:46:28 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	curr_err_command()
{
	char *str;
	
	str = NULL;
	str = ft_strjoin(str, "minish: command not found: ");
	str = ft_strjoin(str, g_curr_err);
	ft_putstr(str);
	free(str);
	g_curr_err = "127";
}