/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:36:54 by xray              #+#    #+#             */
/*   Updated: 2024/12/03 10:53:44 by xray             ###   ########.fr       */
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
		ft_lstclear(&sa);
		ft_lstclear(&sb);
	}
	else 
		return ;
}
