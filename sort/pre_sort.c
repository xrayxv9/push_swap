/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:36:54 by xray              #+#    #+#             */
/*   Updated: 2024/12/01 16:12:39 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"










void	pre_sort(t_list	*sa)
{
	t_psort	ps;
	t_list	*sb;

	sb = NULL;
	ps.len = ft_lstlen(sa);
	if (ps.len > 3)
	{
		get_info(&ps, sa);
		stackb_fill(&sa, &sb, &ps);
	}
	else 
		return ;
}
