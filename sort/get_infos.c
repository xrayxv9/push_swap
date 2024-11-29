/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:36:54 by xray              #+#    #+#             */
/*   Updated: 2024/11/29 16:24:21 by cmorel           ###   ########.fr       */
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
	ps->third = (ps->len - ps->second - ps->first) / 2;
	ps->fourth = ps->len - ps->third - ps->first - ps->second;
	ps->first_l = first_l(ps, s);
	ps->second_l = second_l(s, ps->first_l, ps->second);
	ps->third_l = second_l(s, ps->second_l, ps->third);
	ft_printf("ps->first : %d, ps->first_l : %d\n", ps->first, ps->first_l);
	ft_printf("ps->second: %d, ps->second_l : %d\n", ps->second, ps->second_l);
	ft_printf("ps->third: %d, ps->third_l : %d\n", ps->third, ps->third_l);
	ft_printf("ps->fourth: %d, ps->fourth_l : %s\n", ps->fourth, "(NULL)");
}
