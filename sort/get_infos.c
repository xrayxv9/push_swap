/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:20 by xray              #+#    #+#             */
/*   Updated: 2024/12/03 10:17:53 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"





int	remains(t_list *s, int limit, int limit_len)
{
	t_list	*curr;
	t_list	*tmp;
	t_list	*l;
	int		res;
	
	curr = s;
	l = NULL;
	while (curr)
	{
		tmp = bigger(&l);
		if (ft_lstlen(l) < limit_len && curr->content > limit)
			ft_lstadd_back(&l, ft_lstnew(curr->content));
		else 
		{
		 	if (curr->content > limit)
			{
				if (tmp->content > curr->content)
					tmp->content = curr->content;
			}
		}
		curr = curr->next;
	}
	res = bigger(&l)->content;
	ft_lstclear(&l);
	return (res);
}

void	get_info(t_psort *ps, t_list *s)
{
	ps->first = ps->len / 4;
	ps->second = (ps->len - ps->first) / 3;
	ps->third = (ps->len - ps->second - ps->first) / 2;
	ps->fourth = ps->len - ps->third - ps->first - ps->second;
	ps->to_displace = 0;
	ps->first_l = first_l(ps, s);
	ps->second_l = remains(s, ps->first_l, ps->second);
	ps->third_l = remains(s, ps->second_l, ps->third);
}
