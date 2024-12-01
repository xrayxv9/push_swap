/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:59:21 by xray              #+#    #+#             */
/*   Updated: 2024/12/01 23:04:58 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	reset(t_list **sa, t_list **sb,t_psort ps)
{
	t_list	*curr;

	curr = *sb;
	while (ps.to_displace)
	{
		push(sb, sa, 1);
		curr = curr->next;
		ps.to_displace--;
	}
}


void	fill_b(t_list **sa, t_list **sb,t_psort ps, int limit)
{
	t_list	*curr;
	t_list	*last;

	curr = *sa;
	while (curr)
	{
		last = ft_lstlast(*sa);
		if (curr->content <= limit)
		{
			push(sa, sb, 2);
			rotate(sb, 2);
		}
		else if (last->content < limit)
		{
			rrotate(sa, 1);
			push(sa, sb, 2);
			rotate(sb, 2);
		}
		else
		{
			push(sa, sb, 2);
			ps.to_displace++;
		}
		curr = *sa;
	}
	reset(sa, sb, ps);
}

void	stackb_fill(t_list **sa, t_list **sb, t_psort *ps)
{
	ft_printf("first_l  : %d\n", ps->first_l);
	ft_printf("second_l : %d\n", ps->second_l);
	ft_printf("third_l  : %d\n", ps->third_l);

	fill_b(sa, sb, *ps, ps->first_l);
	fill_b(sa, sb, *ps, ps->second_l);
	fill_b(sa, sb, *ps, ps->third_l);
	fill_b(sa, sb, *ps, 2147483647);
}
