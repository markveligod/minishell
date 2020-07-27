/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:01:31 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/27 09:30:33 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	clear_malloc(t_ptr *ptr)
{
	t_echo		*temp_ec;
	t_cd		*temp_cd;
	t_pwd		*temp_pwd;
	t_export	*temp_exp;
	t_unset		*temp_un;
	t_env		*temp_env;
	t_exit		*temp_exit;
	
	if (ptr->ec != NULL)
		while (ptr->ec)
		{
			temp_ec = ptr->ec->next;
			ft_free_array(ptr->ec->fd);
			ft_free_array(ptr->ec->flag_v);
			free(ptr->ec->line);
			free(ptr->ec);
			ptr->ec = temp_ec;
		}
	if (ptr->base != NULL)
	{
		ft_free_array(ptr->base->flag_base);
		ft_free_array(ptr->base->ar_base);
		free(ptr->base);
	}
	if (ptr->cd != NULL)
		while (ptr->cd)
		{
			temp_cd = ptr->cd->next;
			ft_free_array(ptr->cd->path);
			free(ptr->cd);
			ptr->cd = temp_cd;
		}
	if (ptr->pwd != NULL)
		while (ptr->pwd)
		{
			temp_pwd = ptr->pwd->next;
			ft_free_array(ptr->pwd->arg);
			free(ptr->pwd);
			ptr->pwd = temp_pwd;
		}
	if (ptr->exp != NULL)
		while (ptr->exp)
		{
			temp_exp = ptr->exp->next;
			ft_free_array(ptr->exp->arg);
			free(ptr->exp);
			ptr->exp = temp_exp;		
		}
	if (ptr->un != NULL)
		while (ptr->un)
		{
			temp_un = ptr->un->next;
			ft_free_array(ptr->un->arg);
			free(ptr->un);
			ptr->un = temp_un;		
		}
	if (ptr->env != NULL)
		while (ptr->env)
		{
			temp_env = ptr->env->next;
			ft_free_array(ptr->env->arg);
			free(ptr->env);
			ptr->env = temp_env;		
		}
	if (ptr->exit != NULL)
		while (ptr->exit)
		{
			temp_exit = ptr->exit->next;
			ft_free_array(ptr->exit->arg);
			free(ptr->exit);
			ptr->exit = temp_exit;		
		}
}