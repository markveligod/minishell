/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:16:50 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/25 20:47:46 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	init_struct_base(t_ptr *ptr)
{
	ptr->base = (t_base *)malloc(sizeof(t_base));
	ptr->base->flag_base = (char **)malloc(sizeof(char *) * 1);
}