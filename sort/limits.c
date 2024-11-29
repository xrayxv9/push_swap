/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:45:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/29 15:14:47 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

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
		{
			ft_lstadd_back(&l, ft_lstnew(curr->content));
		}
		else if (curr->content < tmp->content)
			tmp->content = curr->content;
		curr = curr->next;
	}
	res = bigger(&l)->content;
	ft_lstclear(&l);
	return (res);
}

int	second_l(t_list *s, int limit, int limit_len)
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
		if (ft_lstlen(l) < limit_len)
			ft_lstadd_back(&l, ft_lstnew(curr->content));
		else 
		{
			if (curr->content < limit)
			{
				if (tmp->content < curr->content)
					curr->content = tmp->content;
			}
		}
	curr = curr->next;
	}
	res = tmp->content;
	ft_lstclear(&l);
	return (res);
}
