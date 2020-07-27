/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 07:48:29 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/27 09:33:31 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	error(char *str, t_ptr *ptr)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	ft_putstr("\n");
	clear_malloc(ptr);
	main();
}