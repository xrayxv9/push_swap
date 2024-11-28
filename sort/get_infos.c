/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:20 by xray              #+#    #+#             */
/*   Updated: 2024/11/28 17:55:07 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

int	bigger(t_list *l)
{
	t_list	*curr;
	t_list	*tmp;

	tmp = l;
	curr = l;
	while (curr)
	{
		if (tmp->content > curr->content)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp->content);
}

void	replace_bigger(t_list **l, t_list	*curr)
{
	t_list	*c;
	t_list	*tmp;

	tmp = NULL;
	c = *l;
	while (c->next)
	{
		if (curr->content < c->content)
		{
			tmp = curr;
		}
		c = c->next;
	}
	if (tmp)
		ft_printf("test : %d\n", tmp->content);
	if (tmp)
		c = tmp;
}

int	first_l(t_psort *ps, t_list *s)
{
	t_list	*curr;
	t_list	*l;
	int		bg;

	curr = s;
	l = NULL;
	while (curr)
	{
		if (ft_lstlen(l) != ps->first)
		{
			ft_lstadd_back(&l, ft_lstnew(curr->content));
		}
		else
			replace_bigger(&l, curr);
		curr = curr->next;
	}
	print_stack(l);
	bg = bigger(l);
	ft_lstclear(&l);
	return (bg);
}


void	get_info(t_psort *ps, t_list *s)
{
	ps->first = ps->len / 4;
	ps->second = (ps->len - ps->first) / 3;
	ps->third = (ps->len - ps->second - ps->first) / 2;
	ps->fourth = ps->len - ps->third - ps->first - ps->second;
	ps->to_displace = 0;
	ps->first_l = first_l(ps, s);
	ft_printf("first_l = %d", ps->first_l);
}
