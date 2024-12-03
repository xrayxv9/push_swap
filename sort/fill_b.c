/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:59:21 by xray              #+#    #+#             */
/*   Updated: 2024/12/03 10:21:20 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	reset(t_list **sa, t_list **sb, t_psort	*ps, int limit)
{
	t_list	*curr;
	int		code;

	curr = *sb;
	while (ps->to_displace)
	{
		if (curr->content <= limit && curr->content > ps->limit)
			code = 1;
		else
			code = 2;
		curr = curr->next;
		if (code == 1)
			rotate(sb, 2);
		else
			push(sb, sa, 1);
		ps->to_displace--;
	}
}

void	rpr_pr(t_list	**sa, t_list **sb, int code)
{
	if (code == 1)
	{
		push(sa, sb, 2);
		rotate(sb, 2);
	}
	else
	{
		rrotate(sa, 1);
		push(sa, sb, 2);
		rotate(sb, 2);
	}
}

void	fill_b(t_list **sa, t_list **sb,t_psort *ps, int limit)
{
	t_list	*curr;
	t_list	*last;

	curr = *sa;
	while (curr)
	{
		last = ft_lstlast(*sa);
		if (curr->content <= limit && curr->content > ps->limit)
			rpr_pr(sa, sb, 1);
		else if (last->content < limit && last->content > ps->limit)
			rpr_pr(sa, sb, 2);
		else
		{
			push(sa, sb, 2);
			ps->to_displace++;
		}
		curr = *sa;
	}
}

void	stackb_fill(t_list **sa, t_list **sb, t_psort *ps)
{
	int tmp;

	tmp = mini(*sa);
	ft_printf("mini : %d\n", tmp);
	ps->limit = ps->second_l;
	fill_b(sa, sb, ps, ps->third_l);
	ps->limit = ps->first_l;
	reset(sa, sb, ps, ps->second_l);
	ps->limit = tmp;
	fill_b(sa, sb, ps, ps->first_l);
}
