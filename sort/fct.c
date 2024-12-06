/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:29:48 by xray              #+#    #+#             */
/*   Updated: 2024/12/04 03:29:53 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

int	mini(t_list	*sa)
{
	t_list	*curr;
	t_list	*tmp;

	tmp = sa;
	curr = sa->next;
	while (curr)
	{
		if (tmp->content > curr->content)
		{
			tmp = curr;
		}
		curr = curr->next;
	}
	return  (tmp->content - 1);
}

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
