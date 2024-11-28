/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:36:54 by xray              #+#    #+#             */
/*   Updated: 2024/11/28 14:51:24 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"







void	get_info(t_psort *ps)
{
	
}


void	pre_sort(t_list	*s)
{
	t_psort	ps;

	ps.len = ft_lstlen(s);
	if (ps.len > 3)
	{
		get_info(&ps);
	}
	else 
		return ;
}
