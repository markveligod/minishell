/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:16:50 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/26 16:11:59 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minish.h"

void	init_struct_base(t_ptr *ptr)
{
	ptr->base = (t_base *)malloc(sizeof(t_base));
	ptr->base->flag_base = (char **)malloc(sizeof(char *) * 1);
	ptr->base->ar_base = (char **)malloc(sizeof(char *) * 1);
	ptr->base->flag_base[0] = NULL;
	ptr->base->ar_base[0] = NULL;
}