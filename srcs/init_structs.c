/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:16:50 by ckakuna           #+#    #+#             */
/*   Updated: 2020/08/22 06:48:34 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

/*
** иницилизирует структуру ptr
*/

void		init_struct_ptr(t_ptr *ptr)
{
	ptr->base = NULL;
	ptr->command = NULL;
	if (!(ptr->is_export = (char **)malloc(sizeof(char *) * 1)))
		error("Allocation problem!", ptr);
	ptr->is_export[0] = NULL;
}

/*
** иницилизирует структуру base (имя команды и разделитель)
*/

void		init_struct_base(t_ptr *ptr)
{
	if (!(ptr->base = (t_base *)malloc(sizeof(t_base))) ||
		!(ptr->base->flag_base = (char **)malloc(sizeof(char *) * 1)) ||
		!(ptr->base->ar_base = (char **)malloc(sizeof(char *) * 1)))
		error("Allocation problem!", ptr);
	ptr->base->flag_base[0] = NULL;
	ptr->base->ar_base[0] = NULL;
}

/*
** иницилизирует структуру command (список)
*/

t_command	*init_list_command(t_command *new)
{
	if (!(new = (t_command *)malloc(sizeof(t_command))) ||
		!(new->filename = (char **)malloc(sizeof(char *) * 1)) ||
		!(new->flag_v = (char **)malloc(sizeof(char *) * 1)) ||
		!(new->args = (char **)malloc(sizeof(char *) * 1)) ||
		!(new->spaces = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	new->command = ft_strdup("");
	new->args[0] = NULL;
	new->spaces[0] = NULL;
	new->filename[0] = NULL;
	new->flag_v[0] = NULL;
	new->next = NULL;
	return (new);
}
