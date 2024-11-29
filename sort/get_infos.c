/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:36:54 by xray              #+#    #+#             */
/*   Updated: 2024/11/29 15:22:54 by cmorel           ###   ########.fr       */
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

void	get_info(t_psort *ps, t_list *s)
{
	ps->first = ps->len / 4;
	ps->second = (ps->len - ps->first) / 3;
	ps->third = (ps->len - ps->second) / 2;
	ps->fourth = ps->len - ps->third;
	ps->first_l = first_l(ps, s);
	ps->second_l = second_l(s, ps->first_l, ps->second);
	ps->third_l = second_l(s, ps->third_l, ps->third);
}
