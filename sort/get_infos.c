/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:20 by xray              #+#    #+#             */
/*   Updated: 2024/12/01 23:51:29 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

t_list	*bigger(t_list **l)
{
	t_list	*curr;
	t_list	*tmp;

	tmp = *l;
	curr = *l;
	while (curr)
	{
		if (tmp->content < curr->content)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp);
}

int	first_l(t_psort *ps, t_list *s)
{
	t_list	*curr;
	t_list	*l;
	t_list	*tmp;
	int		res;

	curr = s;
	l = NULL;
	while (curr)
	{
		tmp = bigger(&l);
		if (ft_lstlen(l) != ps->first)
			ft_lstadd_back(&l, ft_lstnew(curr->content));
		else if (curr->content < tmp->content)
			tmp->content = curr->content;
		curr = curr->next;
	}
	res = bigger(&l)->content;
	ft_lstclear(&l);
	return (res);
}

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
	res = tmp->content;
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
	ps->second_l = remains(s, ps->second, ps->first_l);
	ps->third_l = remains(s, ps->third, ps->second_l);
}
